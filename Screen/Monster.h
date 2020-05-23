#pragma once
#include "GameObject.h"
#include "Utils.h"

class Map;

class Monster : public GameObject
{
	Map& map;

public:
	Monster(int x, int y, const char* shape, Map& map);
	~Monster();

	void update();

};

