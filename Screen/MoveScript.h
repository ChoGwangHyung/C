#pragma once
#include "Component.h"
#include "GridManager.h"
class MoveScript :
	public Component
{
	GridManager* gm;
	Screen& screen;
	struct BlockShape {
		string shape;
		int width;
		int height;
	};

	vector<BlockShape> blocks{
		{ "\xB2\xB2 \xB2 \xB2", 2, 3},
		{ "\xB2\xB2\xB2\xB2",	2, 2},
		{ "\xB2\xB2\xB2\xB2",	4, 1},
		{ "\xB2\xB2\xB2 \xB2 ", 2, 3},
		{ " \xB2\xB2\xB2\xB2 ", 2, 3},
		{ " \xB2\xB2\xB2 \xB2", 2, 3},
		{ "\xB2 \xB2\xB2 \xB2", 2, 3}
	};

	Vector2 pos;
	int speed;

	int blockShape;
	int nextBlock;

public:
	MoveScript(GameObject* gameObject);
	~MoveScript();

	void start();

	void update();

	void rightRotateShape();
	void leftRotateShape();	
};

