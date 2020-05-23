#include "GameEngine.h"
#include "GameObject.h"
#include "MoveScript.h"
#include "Transform.h"
#include "Utils.h"
#include "Food.h"
#include "Ui.h"
#include "Text.h"

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

	GameObject map("Map");
	map.addComponent<Ui>();
	map.transform->setScale({ 22,12 });
	objs.push_back(&map);

	GameObject scoreUi("ScoreUi");
	scoreUi.addComponent<Ui>();
	scoreUi.addComponent<Text>();
	scoreUi.transform->setPosition({ 30,0 });
	scoreUi.transform->setScale({ 30,10 });
	objs.push_back(&scoreUi);

	for (int i = 0; i < 200; i++) {
		GameObject *food = new GameObject("#", &map, "Food");
		food->addComponent<Food>();
		objs.push_back(food);
	}

	GameObject mino("$ Mino", &map, "Monster");
	mino.addComponent<MoveScript>();
	mino.addComponent<Text>();
	mino.transform->setPosition({ 5,2 });
	objs.push_back(&mino);

	GameObject ghost("@ Ghost", &map, "Monster");
	ghost.addComponent<MoveScript>();
	ghost.addComponent<Text>();
	ghost.transform->setPosition({ 5,5 });
	objs.push_back(&ghost);

	GameObject snake("& Snake", &map, "Monster");
	snake.addComponent<MoveScript>();
	snake.addComponent<Text>();
	snake.transform->setPosition({ 5,8 });
	objs.push_back(&snake);

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
		int i = 0;
		for (auto obj : objs)
		{
			if (obj->isActive() == false)
				objs.erase(objs.begin()+i);
			i++;
		}
		// draw
		for (auto obj : objs)
		{
			obj->traverseDraw();			
		}
		screen.render();
		Sleep(200);		
		Input::EndOfFrame();
	}
	return;
}