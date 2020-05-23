#pragma once
#include "Component.h"
#include "Utils.h"
#include "ScoreManager.h"
#include <vector>

class MoveScirpt;
class GridManager :
	public Component
{	
	ScoreManager* sm;
	
	int width;
	int height;
	Screen& screen;

	char* buffer;
	int highLine;

	const vector<GameObject *>& gameObjects;

public:
	GridManager(GameObject* gameObject);
	~GridManager();

	int getWidth() const { return width; }
	int getHeight() const { return height; }
	void resideInside(const char* shape, Vector2& pos, int w, int h);

	bool isGrounded(const char* shape, const Vector2& pos, int w, int h);
	void placeBlock(const char * shape, const Vector2 & pos, int w, int h);
	void removeLine();

	void findPlacePos(const char* shape, const Vector2& pos, int w, int h);

protected:
	void start();
	void update();
};

