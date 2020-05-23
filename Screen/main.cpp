// Screen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <ctime>
#include "Utils.h"
bool a = true;
using namespace std;

class GameObject {
	char*		shape;
	int			width;
	int			height;
	Position	pos;
	Screen&		screen;

	vector<GameObject *> children;


public:
	GameObject(const char* shape, int width, int height, const Position& pos = Position{ 0, 0 })
		: height(height), width(width),
		shape(nullptr), pos(pos),
		screen(Screen::getInstance()) {
		if (!shape || strlen(shape) == 0 || width == 0 || height == 0)
		{
			this->shape = new char[1];
			this->shape[0] = 'x';
			width = 1;
			height = 1;
		}
		else {
			this->shape = new char[width*height];
			strncpy(this->shape, shape, width*height);
		}
		this->width = width;
		this->height = height;
	}

	virtual ~GameObject() {
		if (shape) { delete[] shape; }
		width = 0, height = 0;
	}

	void add(GameObject* child) {
		if (!child) return;
		children.push_back(child);
	}

	void setShape(const char* shape) {
		if (!shape) return;
		strncpy(this->shape, shape, width*height);
	}

	void setPos(int x, int y) { this->pos.x = x; this->pos.y = y; }

	Position& getPos() { return pos; }

	virtual void draw()
	{
		screen.draw(shape, width, height, pos);

		for (auto child : children) child->draw();
	}

	void internalUpdate()
	{
		update();
		for (auto child : children)
			child->update();
	}

	virtual void update()
	{
	}

	vector<GameObject *>& getChildren() { return children; }
};

void gameOver() {
	a = true;
}
class Block : public GameObject {

	vector<string> sprites;
	int current;
	int boundaryVal;

public:
	bool correct;
	int spritesVal;

	Block(vector<string>& sprites, int w, int h,
		const Position& pos = Position{ 0,0 })
		: sprites(sprites), current(0), correct(false),
		GameObject(sprites[current].c_str(), w, h, pos) {}

	void RightBoundary()
	{
		if (spritesVal == 0) {
			if (current == 0)boundaryVal = 4;
			else if (current == 1)boundaryVal = 3;
		}
		else if (spritesVal == 1) {
			if (current == 0)boundaryVal = 2;
			else if (current == 1)boundaryVal = 3;
			else if (current == 2)boundaryVal = 2;
			else if (current == 3)boundaryVal = 3;
		}
		else if (spritesVal == 2) {
			if (current == 0)boundaryVal = 2;
			else if (current == 1)boundaryVal = 3;
		}
		else if (spritesVal == 3) {
			if (current == 0)boundaryVal = 2;
			else if (current == 1)boundaryVal = 3;
		}
		else if (spritesVal == 4) {
			if (current == 0)boundaryVal = 2;
			else if (current == 1)boundaryVal = 3;
			else if (current == 2)boundaryVal = 2;
			else if (current == 3)boundaryVal = 3;
		}
		else if (spritesVal == 5) {
			if (current == 0)boundaryVal = 2;
			else if (current == 1)boundaryVal = 3;
			else if (current == 2)boundaryVal = 2;
			else if (current == 3)boundaryVal = 3;
		}
	}

	void LeftBoundary()
	{
		if (spritesVal == 0) {
			if (current == 0)boundaryVal = 0;
			else if (current == 1)boundaryVal = -2;
		}
		else if (spritesVal == 1) {
			if (current == 0)boundaryVal = 0;
			else if (current == 1)boundaryVal = 0;
			else if (current == 2)boundaryVal = 0;
			else if (current == 3)boundaryVal = 0;
		}
		else if (spritesVal == 2) {
			if (current == 0)boundaryVal = 0;
			else if (current == 1)boundaryVal = 0;
		}
		else if (spritesVal == 3) {
			if (current == 0)boundaryVal = 0;
			else if (current == 1)boundaryVal = 0;
		}
		else if (spritesVal == 4) {
			if (current == 0)boundaryVal = 0;
			else if (current == 1)boundaryVal = 0;
			else if (current == 2)boundaryVal = 0;
			else if (current == 3)boundaryVal = 0;
		}
		else if (spritesVal == 5) {
			if (current == 0)boundaryVal = 0;
			else if (current == 1)boundaryVal = 0;
			else if (current == 2)boundaryVal = 0;
			else if (current == 3)boundaryVal = 0;
		}
	}

	void update() {

		if (Input::GetKeyDown(KeyCode::Right)) {
			RightBoundary();

			if (getPos().x < Screen::getInstance().getMapWidth() - boundaryVal)
				getPos().x++;
		}

		if (Input::GetKeyDown(KeyCode::Left)) {
			LeftBoundary();

			if (getPos().x > boundaryVal)
				getPos().x--;
		}

		if (Input::GetKeyDown(KeyCode::Up)) {
			current = (current + 1) % sprites.size();
			setShape(sprites[current].c_str());
			if (current != 0 && getPos().x == Screen::getInstance().getMapWidth() - 2)
				getPos().x--;
			else if (current != 2 && getPos().x <= 0)
				getPos().x = 0;
		}

		if (Input::GetKeyDown(KeyCode::Down)) {
			getPos().y += 1;
		}

		if (Input::GetKeyDown(KeyCode::A)) {
			current = (current + 1) % sprites.size();
			setShape(sprites[current].c_str());
			if (current != 0 && getPos().x == Screen::getInstance().getMapWidth() - 2)
				getPos().x--;
			else if (current != 2 && getPos().x <= 0)
				getPos().x = 0;
		}

		if (Input::GetKeyDown(KeyCode::D)) {
			current = (current + 3) % sprites.size();
			setShape(sprites[current].c_str());
			if (current != 0 && getPos().x == Screen::getInstance().getMapWidth() - 2)
				getPos().x--;
			else if (current != 2 && getPos().x <= 0)
				getPos().x = 0;
		}

		getPos().y = (getPos().y + 1) % Screen::getInstance().getMapHeight();
		BlockHeadUp();
	}

	void BlockHeadUp()
	{
		if (spritesVal == 0)
		{
			if (current == 0) {
				if ((getPos().y + 2) == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos() + 2).y*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 3) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 1) {
				if (getPos().y + 5 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
		}
		else if (spritesVal == 1)
		{
			if (current == 0) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 1) {
				if (getPos().y + 3 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 2) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 3) {
				if (getPos().y + 3 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
		}
		else if (spritesVal == 2)
		{
			if (current == 0) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 1) {
				if (getPos().y + 3 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
		}
		else if (spritesVal == 3)
		{
			if (current == 0) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 1) {
				if (getPos().y + 3 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
		}
		else if (spritesVal == 4)
		{
			if (current == 0) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 1) {
				if (getPos().y + 3 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 2) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 3) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
		}
		else if (spritesVal == 5)
		{

			if (current == 0) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 1) {
				if (getPos().y + 3 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 2) {
				if (getPos().y + 4 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 4)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
			if (current == 3) {
				if (getPos().y + 3 == Screen::getInstance().getMapHeight() ||
					Screen::getInstance().getMap(getPos().x + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 1) + (getPos().y + 2)*(Screen::getInstance().getMapWidth())) == '\xDB' ||
					Screen::getInstance().getMap((getPos().x + 2) + (getPos().y + 3)*(Screen::getInstance().getMapWidth())) == '\xDB')
				{
					MapHeadUp();
					correct = true;
				}
			}
		}
		if (getPos().y < 2)
			gameOver();
	}

	void MapHeadUp()
	{
		string temp = sprites[current].c_str();
		int num;

		if (spritesVal == 0)num = 4;
		else num = 3;

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				int index = (getPos().x + j) + ((getPos().y + 1 + i)*(Screen::getInstance().getMapWidth()));
				if (temp[j + (i * num)] == '\xDB')
					Screen::getInstance().setMap(index, '\xDB');
			}
		}

		getPos().y = 0;

		BlockRemove();
	}

	void BlockRemove()
	{
		int ypos[10] = { 0, };
		int num = 0;

		for (int i = 0; i < Screen::getInstance().getMapHeight(); i++)
		{
			bool correct = true;

			for (int j = 0; j < Screen::getInstance().getMapWidth(); j++)
			{
				if (Screen::getInstance().getMap(j + i * Screen::getInstance().getMapWidth()) != '\xDB')
					correct = false;
			}
			if (correct)ypos[num++] = i;
		}
		if (num != 0)
		{
			for (int i = num - 1; i >= 0; i--)
			{
				for (int k = ypos[i]; k > 0; k--)
				{
					for (int j = 0; j < Screen::getInstance().getMapWidth(); j++)
					{
						Screen::getInstance().setMap(j + k * Screen::getInstance().getMapWidth(),
							Screen::getInstance().getMap(j + (k - 1) * Screen::getInstance().getMapWidth()));
					}
				}
			}
		}
	}

	void RanBlock(Block* obj, vector<vector<string>> sprites, int& rannum)
	{
		if (!correct) return;

		free(obj);

		int sizenum;
		if (rannum != 0)sizenum = 3;
		else sizenum = 4;

		obj = new Block{ sprites[rannum], sizenum, sizenum , {Screen::getInstance().getMapWidth() / 2, 0} };

		spritesVal = rannum;

		rannum = rand() % 6;
	}
};

int main()
{
	vector<vector<string>> sprites{
		//ㅡ,ㅣ 블록
		{ "\xDB\xDB\xDB\xDB                ", "  \xDB   \xDB   \xDB   \xDB " },
		//ㅏ,ㅜ,ㅓ,ㅗ 블록
		{"\xDB  \xDB\xDB \xDB  ", "\xDB\xDB\xDB \xDB    ", " \xDB \xDB\xDB  \xDB ", " \xDB \xDB\xDB\xDB   "},
		//ㄹ 블록
		{"\xDB  \xDB\xDB  \xDB ", " \xDB\xDB\xDB\xDB    "},
		//ㄹ 거꾸로 블록
		{ " \xDB \xDB\xDB \xDB  ", "\xDB\xDB  \xDB\xDB   "},
		//ㄴ, ㄱ 블록
		{ "\xDB  \xDB  \xDB\xDB ", "\xDB\xDB\xDB\xDB     ", "\xDB\xDB  \xDB  \xDB ", "     \xDB\xDB\xDB\xDB"},
		//ㄴ, ㄱ 거꾸로 블록
		{" \xDB  \xDB \xDB\xDB ", "\xDB  \xDB\xDB\xDB   ", "\xDB\xDB \xDB  \xDB  ", "\xDB\xDB\xDB  \xDB   "}
	};

	/*vector<string> sprites{ "\xDB\xDB  \xDB  \xDB ",
		" \xDB \xDB\xDB\xDB   ",
		" \xDB  \xDB  \xDB\xDB",
		"   \xDB\xDB\xDB\xDB  "
	};*/
	//vector<string> sprites2{ "\xB2\xB2  ", "  \xB2\xB2" };

	Screen&	 screen = Screen::getInstance();
	vector<GameObject *> gameObjects;

	srand(time(nullptr));

	string mode{ "mode con cols="
		+ to_string(screen.getWidth() + 4)
		+ " lines=" + to_string(screen.getHeight() + 5) };
	system(mode.c_str());
	system("chcp 437");

	int rannum = rand() % 6;
	int sizenum;

	if (rannum != 0)sizenum = 3;
	else sizenum = 4;

	auto parent = new Block{ sprites[rannum], sizenum,sizenum, {screen.getMapWidth() / 2, 0} };
	parent->spritesVal = rannum;
	//auto child = new Block{ sprites2, 2,2, Position{1, 1} };
	//parent->add(child);
	gameObjects.push_back(parent);

	screen.clear(); screen.render();
	rannum = rand() % 6;
	while (a)
	{
		screen.clear();
		for (auto obj : gameObjects) obj->internalUpdate();

		for (auto it = gameObjects.cbegin();
			it != gameObjects.cend(); it++)
			(*it)->draw();

		parent->RanBlock(parent, sprites, rannum);

		screen.screenDraw(sprites, rannum);

		screen.render();
		Sleep(150);

		Input::EndOfFrame();
	}

	system("cls");
		printf("seeeeee\n");
	system("pause");
	return 0;
}

//gameover 함수구현
//맞출때 왼쪽오른쪽