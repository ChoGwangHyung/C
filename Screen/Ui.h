#pragma once
#include "Component.h"
#include "Utils.h"

class Ui
	: public Component
{
	Vector2 scale;

public:
	Ui(GameObject* gameObject);
	~Ui();

	void start();
	void update();
	void draw();
};

