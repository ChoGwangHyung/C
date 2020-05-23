#pragma once
#include "Component.h"
#include "Utils.h"

class Text 
	: public Component
{
	string text;
	string moveCountText;
	Vector2 pos;
	int moveCount;

public:
	Text(GameObject* gameObject);
	~Text();

	void start();
	void update();
	void draw();
};

