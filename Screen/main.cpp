// Screen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <array>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include "Utils.h"

using namespace std;

class GameObject {
	bool		enabled;

protected:

	Position	pos;
	Screen&		screen;
	char*		shape;
	int			width;
	int			height;

	vector<GameObject *> children;
	GameObject*	parent;

public:
	GameObject(const char* shape, int width, int height, const Position& pos = Position{ 0, 0 })
		: height(height), width(width), shape(nullptr), pos(pos), enabled(true), parent(nullptr),
		screen(Screen::getInstance()) {
		if (!shape || strlen(shape) == 0)
			this->shape = nullptr;
		else {
			this->shape = new char[width*height];
			strncpy(this->shape, shape, width*height);
		}
		children.clear();
	}

	GameObject(int width, int height, const Position& pos = Position{ 0, 0 })
		: GameObject(nullptr, width, height, pos)
	{}

	virtual ~GameObject()
	{
		while (children.size() > 0) {
			auto back = children.back();
			children.pop_back();
			delete back;
		}
		if (shape) { delete[] shape; }
		shape = nullptr;
		width = 0, height = 0;
	}

	void setParent(GameObject* parent) {
		this->parent = parent;
	}

	void add(GameObject* child) {
		if (!child) return;

		child->setParent(this);
		children.push_back(child);
	}

	virtual bool isActive() { return enabled; }

	void setActive(bool flag = true) { enabled = flag; }

	void setShape(const char* shape) {
		if (!shape) return;
		strncpy(this->shape, shape, width*height);
	}

	virtual void setPos(int x, int y) { this->pos.x = x; this->pos.y = y; }

	int getWidth() const { return width; }
	int getHeight() const { return height; }

	Position& getPos() { return pos; }

	vector<GameObject *>& getChildren() {
		return children;
	}

	void internalDraw(const Position& inheritedPos = Position{ 0, 0 }) {
		if (!enabled) return;

		draw(inheritedPos);

		for (auto& child : children) child->internalDraw(pos + inheritedPos);
	}

	virtual void draw(const Position& inheritedPos = Position{ 0, 0 }) {
		screen.draw(shape, width, height, pos + inheritedPos);
	}

	void internalUpdate() {
		if (!enabled) return;
		update();
		for (auto& child : children) child->internalUpdate();
	}

	virtual void update() {}

	static const char rect = '\xB2';
};


class Panel : public GameObject {

public:
	Panel(const char* layout, int width, int height, const Position& pos) : GameObject(layout, width, height, pos) {}

	GameObject* pop() {
		auto& children = getChildren();
		auto back = children.back();
		children.pop_back();
		back->setParent(nullptr);
		return back;
	}

	void draw(const Position& inheritedPos) {
		screen.drawRect(Position{ pos.x - 1, pos.y - 1 } +inheritedPos, getWidth() + 2, getHeight() + 2);
	}
};

class Text : public Panel {

public:
	Text(const char* info, const Position& pos) : Panel(info, strlen(info), 1, pos) {}

	void draw(const Position& inheritedPos) {
		screen.draw(shape, width, 1, pos + inheritedPos);
	}
};

class Score : public Text {
	int score;
	char* buf;
	int value;

public:
	Score(const Position& pos) : Text("    ", pos), score(0) {
		buf = new char[strlen(shape) + 1];
	}

	~Score() {
		delete[] buf;
	}

	void addScore(int inc) {
		if (inc < 0) return;
		score += inc;
	}

	void draw(const Position& inheritedPos) {
		sprintf(buf, "%d", value);
		screen.draw(buf, strlen(buf), 1, pos + inheritedPos);
	}

	void setValue(int value) {
		this->value = value;
	}
};

class Map : public Panel {
	char* map;
	int   width;
	int	  height;
	int item_value;
	Score* score;

public:
	Map(int width, int height, const Position& pos)
		: map(new char[width*height]), width(width), height(height),
		Panel(nullptr, width, height, pos), score(nullptr), item_value(width*height)
	{
		for (int i = 0; i < width*height; i++)
			map[i] = '#';
	}

	~Map() { if (map) delete[] map; }

	void draw(const Position& inheritedPos)
	{
		screen.drawRect(Position{ pos.x - 1, pos.y - 1 } +inheritedPos, width + 2, height + 2);
		screen.draw(map, width, height, Position{ pos.x, pos.y } +inheritedPos);
	}

	char* getItem() { return map; }
	void setItem(char* temp) { strcpy(map, temp); }
	void MinusItem() { item_value--; }
	int getItemValue() { return item_value; }
};

class Monster : public GameObject {

	char shape;
	Position pos;
	int random_value;
	Map* map;
	int eatItem_value;
	char* tempItem;

public:
	Monster(char s, Position p)
		:GameObject(1, 1, pos), shape(s), pos(p), eatItem_value(0)
	{
	}

	void update() {


		random_value = rand() % 8;

		if (random_value == 0 && pos.x > 0 && pos.y > 0) {
			pos.x -= 1;
			pos.y -= 1;
		}
		else if (random_value == 1 && pos.y > 0) {
			pos.y -= 1;
		}
		else if (random_value == 2 && pos.x < map->getWidth() && pos.y > 0) {
			pos.x += 1;
			pos.y -= 1;
		}
		else if (random_value == 3 && pos.x > 0) {
			pos.x -= 1;
		}
		else if (random_value == 4 && pos.x < map->getWidth()) {
			pos.x += 1;
		}
		else if (random_value == 5 && pos.x > 0 && pos.y < map->getHeight() - 1) {
			pos.x -= 1;
			pos.y += 1;
		}
		else if (random_value == 6 && pos.y < map->getHeight() - 1) {
			pos.y += 1;
		}
		else if (random_value == 7 && pos.x < map->getWidth() && pos.y < map->getHeight() - 1) {
			pos.x += 1;
			pos.y += 1;
		}
		eatItem();
	}

	void draw(const Position& inheritedPos) {
		screen.draw(&shape, width, height, pos + inheritedPos);
	}

	void setMap(Map* map) {
		this->map = map;
	}

	void eatItem() {
		tempItem = map->getItem();
		if (tempItem[pos.x + (pos.y*map->getWidth())] == '#') {
			tempItem[pos.x + (pos.y*map->getWidth())] = ' ';
			eatItem_value++;
			map->MinusItem();
			map->setItem(tempItem);
		}
	}

	int get_eatItem() { return eatItem_value; }

	char getShape() { return shape; }
};


int main()
{
	Screen&	 screen = Screen::getInstance();
	vector<GameObject *> gameObjects;

	string mode = "mode con cols=" + to_string(screen.getWidth() + 10);
	mode += " lines=" + to_string(screen.getHeight() + 5);

	std::system(mode.c_str());
	std::system("chcp 437");

	auto main = new Map(20, 10, Position{ 1, 1 });
	auto& children = main->getChildren();
	main->add(new Monster('\x83', Position{ 1,1 }));
	main->add(new Monster('\x88', Position{ 1,2 }));
	main->add(new Monster('\x93', Position{ 1,3 }));
	static_cast<Monster *>(children[0])->setMap(main);
	static_cast<Monster *>(children[1])->setMap(main);
	static_cast<Monster *>(children[2])->setMap(main);

	auto scorePanel = new Panel(nullptr, screen.getWidth() / 2 - 2, 10, Position{ screen.getWidth() / 2 + 1, 1 });
	scorePanel->add(new Text("Remain Item Value : ", Position{ 1, 0 }));
	scorePanel->add(new Text("All Move Value    : ", Position{ 1, 1 }));
	scorePanel->add(new Text("\x83 : ", Position{ 1, 2 }));
	scorePanel->add(new Text("\x88 : ", Position{ 1, 3 }));
	scorePanel->add(new Text("\x93 : ", Position{ 1, 4 }));
	auto Iscore = new Score(Position{ 21, 0 });
	scorePanel->add(Iscore);
	auto Mscore = new Score(Position{ 21, 1 });
	scorePanel->add(Mscore);
	int moveValue = 0;
	auto score1 = new Score(Position{ 5, 2 });
	scorePanel->add(score1);
	auto score2 = new Score(Position{ 5, 3 });
	scorePanel->add(score2);
	auto score3 = new Score(Position{ 5, 4 });
	scorePanel->add(score3);

	gameObjects.push_back(main);
	gameObjects.push_back(scorePanel);

	screen.clear(); screen.render();

	while (!Input::GetKeyDown(KeyCode::Esc)) {
		screen.clear();
		Iscore->setValue(main->getItemValue());
		Mscore->setValue(moveValue++);
		score1->setValue(static_cast<Monster *>(children[0])->get_eatItem());
		score2->setValue(static_cast<Monster *>(children[1])->get_eatItem());
		score3->setValue(static_cast<Monster *>(children[2])->get_eatItem());

		for (auto obj : gameObjects) obj->internalUpdate();

		for (auto it = gameObjects.cbegin();
			it != gameObjects.cend(); it++)
			(*it)->internalDraw();

		screen.render();
		Sleep(2000);

		Input::EndOfFrame();
	}

	while (gameObjects.size() > 0) {
		auto back = gameObjects.back();
		gameObjects.pop_back();
		delete back;
	}

	return 0;
}