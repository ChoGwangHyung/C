#include "Component.h"
#include "Transform.h"


Transform::Transform(GameObject* gameObject,
	const string& shape,
	const Vector2& position,
	const Vector2& rotation,
	const Vector2& scale)
	: position(position),
	rotation(rotation),
	scale(scale),
	shape(shape),
	screen(Screen::getInstance()),
	Component(gameObject)
{

}

Transform::~Transform()
{
}

void Transform::start() {}

void Transform::update()
{
	if (shape == "") return;
	for (int y = 0; y < scale.Y(); y++)
		for (int x = 0; x < scale.X(); x++)
			if (shape[y*scale.X() + x] != ' ')
				screen.draw(&shape[y*scale.X() + x], 1, 1, { position.x + x,position.y + y });
}
