#include "Ui.h"
#include "GameObject.h"
#include "Transform.h"

Ui::Ui(GameObject * gameObject)
	: Component(gameObject)
{
}

Ui::~Ui()
{
}

void Ui::start()
{
	scale = gameObject->getTransform()->getScale();
}

void Ui::update()
{
}

void Ui::draw()
{
	Screen::getInstance().drawRect(gameObject->getTransform()->getPosition(), scale.X(), scale.Y());
}
