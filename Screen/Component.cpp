#include "Component.h"
#include "GameObject.h"
#include "Utils.h"


Component::Component(GameObject* gameObject)
	: gameObject(gameObject),
	transform(gameObject->getTransform())
{
	if (transform == nullptr) {
		transform = gameObject->getTransform();
	}
}


Component::~Component()
{
}