#pragma once
#include "Component.h"
#include "Utils.h"

class ScoreManager :
	public Component
{	
	Screen& screen;
	int score;

	int width;
	int height;

	string scoreText;

public:
	ScoreManager(GameObject* gameObject);
	~ScoreManager();
	
	void start();

	void update();

	void plusScore(int plusVal) { score += plusVal; }	
};

