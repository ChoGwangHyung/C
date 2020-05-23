#include "GridManager.h"
#include "GameObject.h"
#include "Transform.h"



GridManager::GridManager(GameObject* gameObject)
	: Component(gameObject), screen(Screen::getInstance()),
	width(20), height(40), gameObjects(GameObject::GetGameObjects()), highLine(height - 1), sm(nullptr)
{
}


GridManager::~GridManager()
{
}

void GridManager::start()
{
	auto score = GameObject::Find("score");
	if (score == nullptr) return;
	sm = static_cast<ScoreManager *>(score->getComponent<ScoreManager>());
	
	buffer = new char[(width - 1)*(height - 1)];
	memset(buffer, ' ', (width - 1)*(height - 1));
	highLine = height - 1;
}

void GridManager::update()
{
	screen.drawRect(Vector2{ 0.0f, 0.0f }, width + 1, height + 1);
	screen.draw(buffer, width - 1, height - 1, { 1,1 });
}

void GridManager::resideInside(const char* shape, Vector2& pos, int w, int h)
{
	int x = pos.X();
	int y = pos.Y();
	if (x <= 0)  pos.x = 1;
	else if (x + w >= width) pos.x = width - w;

	if (highLine > y + h)return;

	int* Lboundary = new int[h];
	int* Rboundary = new int[h];

	int boundarySeq = 0;

	for (int by = 0; by < h; by++) {
		for (int bx = 0; bx < w; bx++)
			if (shape[by*w + bx] == '\xB2') {
				Lboundary[boundarySeq] = bx;
				break;
			}
		boundarySeq++;
	}
	boundarySeq = 0;
	for (int by = 0; by < h; by++) {
		for (int bx = w - 1; bx >= 0; bx--)
			if (shape[by*w + bx] == '\xB2') {
				Rboundary[boundarySeq] = bx;
				break;
			}
		boundarySeq++;
	}

	for (int i = 0; i < boundarySeq; i++) {
		if (buffer[(y + i)*(width - 1) + x + Lboundary[i] - 1] == '\xB2') { pos.x += 1; break; }
		else if (buffer[(y + i)*(width - 1) + x + Rboundary[i] - 1] == '\xB2') { pos.x -= 1; break; }
	}

	free(Lboundary);
	free(Rboundary);
}

bool GridManager::isGrounded(const char * shape, const Vector2 & pos, int w, int h)
{
	bool isground = false;

	if (highLine > pos.y + h)return isground;

	int* xboundary = new int[w];
	int* yboundary = new int[w];

	int boundarySeq = 0;

	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++)
			if (shape[y*w + x] == '\xB2') {
				xboundary[boundarySeq] = x;
				yboundary[boundarySeq] = y;
			}
		boundarySeq++;
	}

	for (int i = 0; i < boundarySeq; i++)
		if (buffer[(pos.Y() + yboundary[i] + 1)*(width - 1) + pos.X() + xboundary[i] - 1] == '\xB2' || (pos.y + h >= height - 1))
			isground = true;

	free(xboundary);
	free(yboundary);

	return isground;
}

void GridManager::placeBlock(const char * shape, const Vector2 & pos, int w, int h)
{
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			if (shape[y*w + x] == '\xB2')
				buffer[(pos.Y() + y)*(width - 1) + pos.X() + x - 1] = '\xB2';
	if (pos.y < highLine)	highLine = pos.y;
	
	sm->plusScore(10);

	removeLine();
}

void GridManager::removeLine()
{
	int combo = 0;

	for (int y = height - 2; y >= highLine; y--) {
		bool remove = true;

		for (int x = 0; x < width - 1; x++) {
			if (buffer[y*(width - 1) + x] == ' ') {
				remove = false;
				break;
			}
		}
		if (remove) {
			for (int d = y; d >= highLine; d--) {
				for (int x = 0; x < width - 1; x++)
					buffer[d*(width - 1) + x] = buffer[(d - 1)*(width - 1) + x];
			}
			combo++;
		}
	}

	sm->plusScore(combo * 100);
}

void GridManager::findPlacePos(const char * shape, const Vector2 & pos, int w, int h)
{
	for (int i = pos.Y() + h - 1; i < height && buffer[(i - 1)*(width - 1) + pos.X() - 1] != '\xB2'; i++)
		screen.draw("\xFA", 1, 1, { pos.x,(float)i });
	for (int i = pos.Y() + h - 1; i < height && buffer[(i - 1)*(width - 1) + pos.X() + w - 2] != '\xB2'; i++)
		screen.draw("\xFA", 1, 1, { pos.x + w - 1,(float)i });
}