#include "GameEngine.h"
#include "GameObject.h"
#include "MoveScript.h"
#include "GridManager.h"
#include "ScoreManager.h"
#include <ctime>

GameEngine* GameEngine::instance = nullptr;

GameEngine& GameEngine::getInstance() {
	if (instance == nullptr) {
		instance = new GameEngine();
	}
	return *instance;
}


GameEngine::GameEngine() 
	: screen(Screen::getInstance()) {
	string mode = "mode con cols=" + to_string(screen.getWidth() + 10);
	mode += " lines=" + to_string(screen.getHeight() + 5);

	std::system(mode.c_str());
	std::system("chcp 437");
	screen.clear(); screen.render();
}

void GameEngine::mainLoop() {

	auto& objs = GameObject::gameObjects;

	GameObject* map = new GameObject("map", nullptr, "map", "", Vector2{ 20, 40 });
	GameObject::Add(map);
	map->addComponent<GridManager>();
	auto gm = static_cast<GridManager *>(map->getComponent<GridManager>());	

	GameObject* block = new GameObject("block", map, "block", "", Vector2{ 10,1 });
	block->addComponent<MoveScript>();
	objs.push_back(block);

	GameObject* score = new GameObject("score", nullptr, "score", "", Vector2{ 20,10 });	
	score->addComponent<ScoreManager>();
	objs.push_back(score);
	
	for (auto obj : objs)
	{
		obj->traverseStart();
	}

	while (!Input::GetKeyDown(KeyCode::Esc)) {
		screen.clear();
		// update		
		for (auto obj : objs)
		{
			obj->traverseUpdate();
		}
		// erase in active objects

		// draw

		screen.render();
		Sleep(100);

		Input::EndOfFrame();
	}

	while (objs.size())
	{
		auto obj = objs.back();
		objs.pop_back();
		delete obj;
	}

	

	return;
}