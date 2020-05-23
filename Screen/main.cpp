// Screen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Utils.h"

using namespace std;

struct Mine {
	int num;
	bool clicked;
};

class Screen {
	int width;
	int height;

	static Screen* instance;
	Screen(int width = 70, int height = 25)
		: width(width), height(height),
		canvas(new char[(width + 1)*height])
	{
		Borland::initialize();
	}
public:
	char* canvas;

	static Screen& getInstance() {
		if (instance == nullptr) {
			instance = new Screen();
		}
		return *instance;
	}

	~Screen() {
		if (instance) {
			delete[] canvas;
			instance = nullptr;
		}
	}

	void draw(const char* shape, int w, int h, const Position& pos)
	{
		if (!shape) return;
		for (int i = 0; i < h; i++)
		{
			strncpy(&canvas[pos.x + (pos.y + i)*(width + 1)], &shape[i*w], w);
		}
	}

	void render()
	{
		for (int i = 0; i < height; i++)
			canvas[width + i * (width + 1)] = '\n';
		canvas[width + (height - 1) * (width + 1)] = '\0';
		Borland::gotoxy(0, 0);
		cout << canvas;
	}

	void clear()
	{
		memset(canvas, '.', (width + 1)*height);
		canvas[width + (height - 1)*(width + 1)] = '\0';
	}

	void GameOver()
	{
		memset(canvas, ' ', (width + 1)*height);
		canvas[width + (height - 1)*(width + 1)] = '\0';
		render();
		Borland::gotoxy(30, 10);
		cout << "GameOver" << endl;
	}
};

Screen* Screen::instance = nullptr;

class MineObject {
	int width;
	int height;
	int randMine[100];
	int mineValue;

public:
	Mine* mine;
	bool Gameover;

	MineObject(int width, int height)
		: height(height), width(width), Gameover(false), mineValue(100),
		mine(new Mine[(width + 1)*height])
	{
		createMine();
	}

	virtual ~MineObject() {
		width = 0, height = 0;
		mine = nullptr;
	}

	void createMine()
	{
		//지뢰 초기화
		for (int i = 0; i < (width + 1)*height; i++) {
			mine[i].num = 0;
			mine[i].clicked = false;
		}

		//중복되지 않게 랜덤으로 지뢰넣기
		for (int i = 0; i < mineValue; i++) {
			while (true) {
				randMine[i] = rand() % ((width + 1)*height);
				bool isSame = false;

				for (int j = 0; j < i; j++)
				{
					if (randMine[j] == randMine[i])
						isSame = true;
				}
				if (!isSame && (randMine[i] - width) % (width + 1) != 0)break;
			}
			mine[randMine[i]].num = -1;
			//서
			if (randMine[i] % (width + 1) != 0) {
				if (mine[randMine[i] - 1].num != -1)
					mine[randMine[i] - 1].num++;
			}
			//동
			if ((randMine[i] - (width - 1)) % (width + 1) != 0) {
				if (mine[randMine[i] + 1].num != -1)
					mine[randMine[i] + 1].num++;
			}
			//북
			if (randMine[i] > width) {
				if (mine[randMine[i] - (width + 1)].num != -1)
					mine[randMine[i] - (width + 1)].num++;
			}
			//북서
			if ((randMine[i] > width && randMine[i] % (width + 1) != 0)) {
				if (mine[randMine[i] - (width + 2)].num != -1)
					mine[randMine[i] - (width + 2)].num++;
			}
			//북동
			if ((randMine[i] > width && (randMine[i] - (width - 1)) % (width + 1) != 0)) {
				if (mine[randMine[i] - width].num != -1)
					mine[randMine[i] - width].num++;
			}
			//남
			if (randMine[i] < (width + 1) * (height - 1)) {
				if (mine[randMine[i] + (width + 1)].num != -1)
					mine[randMine[i] + (width + 1)].num++;
			}
			//남서
			if ((randMine[i] < (width + 1) * (height - 1) && randMine[i] % (width + 1) != 0)) {
				if (mine[randMine[i] + width].num != -1)
					mine[randMine[i] + width].num++;
			}
			//남동
			if ((randMine[i] < (width + 1) * (height - 1) && (randMine[i] - (width - 1)) % (width + 1) != 0)) {
				if (mine[randMine[i] + (width + 2)].num != -1)
					mine[randMine[i] + (width + 2)].num++;
			}
		}
	}

	void findNoMine(int index, char* map)
	{
		if (mine[index].clicked || mine[index].num == -1) return;

		mine[index].clicked = true;
		map[index] = ' ';

		if (mine[index].num != 0) {
			map[index] = mine[index].num + 48;
			return;
		}

		//서
		if (index % (width + 1) != 0) {
			findNoMine(index - 1, map);
		}
		//동
		if ((index - (width - 1)) % (width + 1) != 0) {
			findNoMine(index + 1, map);
		}
		//북
		if (index > width) {
			findNoMine(index - (width + 1), map);
		}
		//북서
		if ((index > width && index % (width + 1) != 0)) {
			findNoMine(index - (width + 2), map);
		}
		//북동
		if ((index > width && (index - (width - 1)) % (width + 1) != 0)) {
			findNoMine(index - width, map);
		}
		//남
		if (index < (width + 1) * (height - 1)) {
			findNoMine(index + (width + 1), map);
		}
		//남서
		if ((index < (width + 1) * (height - 1) && index % (width + 1) != 0)) {
			findNoMine(index + width, map);
		}
		//남동
		if ((index < (width + 1) * (height - 1) && (index - (width - 1)) % (width + 1) != 0)) {
			findNoMine(index + (width + 2), map);
		}
	}

	void exploMine(char* map)
	{
		for (int i = 0; i < mineValue; i++)
			map[randMine[i]] = 'X';
	}

	void click(const Position& pos, char* map)
	{
		if (mine[pos.x + (pos.y * (width + 1))].clicked)return;

		if (mine[pos.x + (pos.y * (width + 1))].num == -1) {
			exploMine(map);
			Gameover = true;
		}
		else {
			findNoMine(pos.x + (pos.y * (width + 1)), map);
		}
	}
};

int main()
{
	Screen&	 screen = Screen::getInstance();
	MineObject mine(70, 25);
	INPUT_RECORD InputRecord;
	DWORD Events;

	screen.clear();
	screen.render();
	while (true)
	{

		screen.render();
		Sleep(30);

		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &InputRecord, 1, &Events);
		if (InputRecord.EventType == MOUSE_EVENT) {
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
				COORD coord;
				coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
				coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				Position pos;
				pos.x = InputRecord.Event.MouseEvent.dwMousePosition.X;
				pos.y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
				mine.click(pos, screen.canvas);
			}
		}
		if (mine.Gameover) {
			screen.GameOver();
			return 0;
		}
	}

	return 0;
}