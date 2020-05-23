#include "Text.h"
#include "GameObject.h"
#include "Transform.h"

Text::Text(GameObject * gameObject)
	: Component(gameObject)
{
}

Text::~Text()
{
}

void Text::start()
{
	moveCount = 0;
	if (gameObject->getTag() == "Monster")
	{
		static int seq = 0;
		GameObject* scoreUi = GameObject::Find("ScoreUi");
		pos = { scoreUi->getTransform()->getPosition().x + 1, scoreUi->getTransform()->getPosition().y + 1 + seq };
		seq++;
	}
	else
		pos = { gameObject->getTransform()->getPosition().x + 1, gameObject->getTransform()->getScale().y - 3 };
}

void Text::update()
{
	if (gameObject->getTag() == "Monster")
		text = gameObject->getName() + " ate Food : " + to_string(gameObject->ateFood());
	else
	{
		text = "Food Remain : " + to_string(GameObject::FindTag("Food").size());
		moveCountText = "Move Count : " + to_string(moveCount++);
		Screen::getInstance().draw(moveCountText.c_str(), moveCountText.size(), 1, { pos.x, pos.y +1 });
	}
}

void Text::draw()
{
	Screen::getInstance().draw(text.c_str(), text.size(), 1, pos);
}
