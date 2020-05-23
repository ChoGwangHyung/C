#pragma once
#include "Component.h"
#include "Utils.h"
#include <array>

class MoveScript :
	public Component
{
	array<Vector2, 9> targetPos{ Vector2{0, 0},
			Vector2{-1, 0}, Vector2{1, 0}, Vector2{0, -1}, Vector2{0,1},
			Vector2{-1, -1}, Vector2{-1, 1}, Vector2{1, -1}, Vector2{1, 1} };

	Vector2 pos;	
	
	Vector2 mapScale;
	

public:
	MoveScript(GameObject* gameObject);
	~MoveScript();

	void start();

	void update();

	void draw();
};

