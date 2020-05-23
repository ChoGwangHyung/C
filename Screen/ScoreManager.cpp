#include "ScoreManager.h"
#include "GameObject.h"

ScoreManager::ScoreManager(GameObject* gameObject)
	: Component(gameObject), screen(Screen::getInstance())
	, score(0), width(20), height(8)
{
}


ScoreManager::~ScoreManager()
{
}

void ScoreManager::start()
{
	score = 0;
}

void ScoreManager::update()
{
	scoreText = "Score : " + to_string(score);
	screen.drawRect(Vector2{ 25.0f, 0.0f }, width + 1, height + 1);
	screen.draw("Next : ", 7, 1, { 26.0f, 2.0f });
	screen.draw(scoreText.c_str(), scoreText.size(), 1, { 26.0f, 6.0f });
}
