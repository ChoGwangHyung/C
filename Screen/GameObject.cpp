#include "GameObject.h"
#include "Transform.h"

/* STATIC VARIABLES and FUNCTIONS*/
vector<GameObject*> GameObject::gameObjects;

GameObject* GameObject::Find(const string& path) {
	for (auto find : gameObjects)
	{
		if (find->name == path)
			return find;
	}
}

vector<GameObject *> GameObject::FindTag(const string & path)
{
	vector<GameObject*> FindAll;
	for (auto find : gameObjects)
	{
		if (find->tag == path)
			FindAll.push_back(find);
	}
	return FindAll;
}

/* General variables and functions */

GameObject::GameObject(const string& name, GameObject* parent, const string& tag)
	: name(name), tag(tag), enabled(true), parent(parent), foodVal(0),
	transform(new Transform(this)) {
	components.clear();
	components.push_back(transform);
}

GameObject::~GameObject() {}

void GameObject::traverseStart() {
	if (enabled == false) return;

	for (auto comp : components)
	{
		comp->start();
	}
	for (auto child : children)
	{
		child->traverseStart();
	}
}

void GameObject::traverseUpdate() {
	if (enabled == false) return;

	for (auto comp : components)
	{
		comp->update();
	}
	for (auto child : children)
	{
		child->traverseUpdate();
	}
}

void GameObject::traverseDraw()
{
	if (enabled == false) return;

	for (auto comp : components)
	{
		comp->draw();
	}
	for (auto child : children)
	{
		child->traverseDraw();
	}
}