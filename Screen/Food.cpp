#include "Food.h"
#include "GameObject.h"
#include "Transform.h"
#include "MoveScript.h"


Food::Food(GameObject* gameObject)
	: Component(gameObject)
{
}


Food::~Food()
{
}

void Food::start()
{	
	Vector2 mapScale = gameObject->getParent()->getTransform()->getScale();

	static int createFood = 0;
	Vector2 pos;
	pos.x = createFood % (mapScale.X() - 2) + 1;
	pos.y = (createFood / (mapScale.X() - 2)) + 1;
	gameObject->getTransform()->setPosition(pos);
	createFood++;

	ifStart = true;
}

void Food::update()
{
	if (ifStart) 
	{ 
		ifStart = false; 
		return; 
	}
	
	OnTriggerEnter();
}

void Food::draw()
{
	Screen::getInstance().draw(gameObject->getName().c_str(), 1, 1, gameObject->getTransform()->getPosition());
}

void Food::OnTriggerEnter()
{
	vector<GameObject*> monster = GameObject::FindTag("Monster");
	for (auto mon : monster)
	{
		if (mon->getTransform()->getPosition() == gameObject->getTransform()->getPosition())
		{
			mon->eatFood();
			gameObject->setActive(false);
			return;
		}
	}
}
