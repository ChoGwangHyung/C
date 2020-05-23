#include "GameObject.h"
#include "MoveScript.h"
#include "Transform.h"
#include "Utils.h"
#include <time.h>

using namespace std;

MoveScript::MoveScript(GameObject* gameObject)
	: Component(gameObject), gm(nullptr), pos(10, 0), speed(1), screen(Screen::getInstance())
{

}


MoveScript::~MoveScript()
{
}

void MoveScript::start()
{
	srand(time(NULL));

	auto map = GameObject::Find("map");
	if (map == nullptr) return;
	gm = static_cast<GridManager *>(map->getComponent<GridManager>());

	nextBlock = rand() % blocks.size();
	pos = { 10,0 };
	speed = 1;
}

void MoveScript::update()
{
	if (!GameObject::Find("block")) return;

	if (this->transform->getShape() == "") {
		blockShape = nextBlock;
		nextBlock = rand() % blocks.size();
		this->transform->setPosition(pos);
		this->transform->setShape(blocks[blockShape].shape);
		this->transform->setScale({ blocks[blockShape].width ,blocks[blockShape].height });
	}

	if (Input::GetKeyDown(KeyCode::Right)) {
		pos.x++;
	}
	if (Input::GetKeyDown(KeyCode::Left)) {
		pos.x--;
	}
	if (Input::GetKeyDown(KeyCode::Down)) {
		speed *= 2;
	}
	if (Input::GetKeyDown(KeyCode::Up)) {
		leftRotateShape();
	}
	if (Input::GetKeyDown(KeyCode::A)) {
		leftRotateShape();
	}
	if (Input::GetKeyDown(KeyCode::S)) {
		rightRotateShape();
	}
	pos.y += speed;

	gm->resideInside(this->transform->getShape().c_str(), pos, this->transform->getScale().X(), this->transform->getScale().Y());
	transform->setPosition(pos);

	gm->findPlacePos(this->transform->getShape().c_str(), pos, this->transform->getScale().X(), this->transform->getScale().Y());

	if (gm->isGrounded(this->transform->getShape().c_str(), pos, this->transform->getScale().X(), this->transform->getScale().Y())) {
		gm->placeBlock(this->transform->getShape().c_str(), pos, this->transform->getScale().X(), this->transform->getScale().Y());

		this->transform->setShape("");
		pos = { 10,0 };
		speed = 1;
	}

	screen.draw(blocks[nextBlock].shape.c_str(), blocks[nextBlock].width, blocks[nextBlock].height, { 38.0f,1.0f });
}

void MoveScript::rightRotateShape()
{
	Vector2 scale = { this->transform->getScale().X(), this->transform->getScale().Y() };
	static char* shape = new char[scale.X()*scale.Y()];
	for (int y = 0; y < scale.Y(); y++)
		for (int x = 0; x < scale.X(); x++)
			shape[scale.Y() - 1 + scale.Y()*x - y] = this->transform->getShape()[y*scale.X() + x];
	this->transform->setShape(shape);

	swap(scale.x, scale.y);
	this->transform->setScale(scale);
}

void MoveScript::leftRotateShape()
{
	Vector2 scale = { this->transform->getScale().X(), this->transform->getScale().Y() };
	static char* shape = new char[scale.X()*scale.Y()];
	for (int y = 0; y < scale.Y(); y++)
		for (int x = 0; x < scale.X(); x++)
			shape[(scale.X() - 1 - x)*scale.Y() + y] = this->transform->getShape()[y*scale.X() + x];
	this->transform->setShape(shape);

	swap(scale.x, scale.y);
	this->transform->setScale(scale);
}
