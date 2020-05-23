#include "GameObject.h"
#include "MoveScript.h"
#include "Utils.h"
#include "Transform.h"
#include <time.h>


using namespace std;

MoveScript::MoveScript(GameObject* gameObject)
	: Component(gameObject)
{

}


MoveScript::~MoveScript()
{
}

void MoveScript::start()
{
	srand(time(NULL));
	pos = gameObject->getTransform()->getPosition();	
	mapScale = gameObject->getParent()->getTransform()->getScale();
}

void MoveScript::update()
{
	pos += targetPos[rand() % targetPos.size()];
	while (pos.x >= mapScale.x - 1 || pos.x <= 0 || pos.y >= mapScale.y - 1 || pos.y <= 0)
		pos += targetPos[rand() % targetPos.size()];
	gameObject->getTransform()->setPosition(pos);
}

void MoveScript::draw()
{
	Screen::getInstance().draw(gameObject->getName().c_str(), 1, 1, gameObject->getTransform()->getPosition());
}