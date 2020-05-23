#pragma once
#include "Component.h"

class Food
	: public Component
{	
	bool ifStart;

public:
	Food(GameObject* gameObject);
	~Food();

	void start();
	void update();
	void draw();
	void OnTriggerEnter();
};

