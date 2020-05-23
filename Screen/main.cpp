#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void draw(char* loc, const char* face)
{
	strncpy(loc, face, strlen(face));
}

class Screen {
	int size;
	char* screen;

public:
	Screen(int sz) : size(sz), screen(new char[sz + 1]) {}
	~Screen() { delete[] screen; }

	void draw(int pos, const char* face)
	{
		if (face == nullptr) return;
		if (pos < 0 || pos >= size) return;
		strncpy(&screen[pos], face, strlen(face));
	}

	void render()
	{
		printf("%s\r", screen);
	}

	void clear()
	{
		memset(screen, ' ', size);
		screen[size] = '\0';
	}

	int length()
	{
		return size;
	}

};

class GameObject {
protected:
	int pos;
	char face[50];
	Screen* screen;

public:
	GameObject(int pos, const char* face, Screen* screen)
		: pos(pos), screen(screen)
	{
		strcpy(this->face, face);
	}

	int getPosition()
	{
		return pos;
	}
	void setPosition(int pos)
	{
		this->pos = pos;
	}
	virtual void draw()
	{
		screen->draw(pos, face);
	}
};

class Player : public GameObject {
	char change_face[20];
	bool right_move;
	bool left_move;
	bool poison;
	bool ready_poison;
	int life;
	int hittime;
	int hitcount;
	int cooltime;
public:
	Player(int pos, const char* face, Screen* screen, const char* change_face, int life)
		: GameObject(pos, face, screen), right_move(true), left_move(false), life(life),
		poison(false), ready_poison(false), hitcount(0), hittime(0)
	{
		strcpy(this->change_face, change_face);
	}

	void draw()
	{
		if (life <= 0) {
			setPosition(-1);
			return;
		}
		if (right_move)
			screen->draw(pos, face);
		if (left_move)
			screen->draw(pos, change_face);
	}
	void moveLeft()
	{
		right_move = false;
		left_move = true;
		setPosition(getPosition() - 1);
	}

	void moveRight()
	{
		left_move = false;
		right_move = true;
		setPosition(getPosition() + 1);
	}

	void update(int enemy_pos)
	{
		//독 공격
		if (hittime > 14)
			life -= 2;
		if (pos >= enemy_pos-9&&pos<=enemy_pos+9)
			poison = true;
		if (poison) {
			if (hitcount < 3) {
				hittime++;
				if (hittime > 15) {
					hittime = 0;
					cooltime = 0;
					hitcount++;
				}
			}
			else {
				ready_poison = true;
				poison = false;
			}
		}
		if (ready_poison)
			cooltime++;
		if (cooltime > 45) {
			ready_poison = false;
			hitcount = 0;
		}
	}

	bool player_moveRight()
	{
		return right_move;
	}
	//life 관련
	int how_life()
	{
		return life;
	}
	int check_life(int curlife)
	{
		life = curlife;
		return life;
	}
	//독관련
	bool poison_status()
	{
		return poison;
	}
	int cool_time()
	{
		return cooltime;
	}
	int hit_time()
	{
		return hittime;
	}
	
};

class Enemy : public GameObject {
	int life;
	int movetime;
	int appeartime;
	bool appear;
public:
	Enemy(int pos, const char* face, Screen* screen, int life)
		: GameObject(pos, face, screen), life(life), movetime(0), appeartime(150), appear(true)
	{
	}

	void draw()
	{
		appeartime--;
		if (appeartime < 0) {
			if (life <= 0) {
				setPosition(-10);
				appear = true;
				return;
			}
			appearRandom();
			movetime++;
			GameObject::draw();
		}
	}

	void appearRandom()
	{
		if (appear == false)return;
		setPosition(getPosition() + rand() % 70);
		appear = false;
	}

	void update(int hittime, int player_pos)
	{
		int pos = getPosition();
		//움직이기
		if (player_pos > pos && movetime > 30) {
			pos++;
			movetime = 0;
		}
		else if (player_pos <= pos && movetime > 30) {
			pos--;
			movetime = 0;
		}
		setPosition(pos);
		//총알 맞았을 때
		if (hittime == 14)
			life--;
		
	}
	
	//life 관련
	int how_life()
	{
		return life;
	}

	int check_life(int curlife)
	{
		life = curlife;
		return life;
	}
};

class Bullet : public GameObject {
	bool isFiring;
	bool bullet_move;
	bool hit;
	bool reload;
	int reloadtime;
public:
	Bullet(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen), isFiring(false), hit(false), reload(false),
		reloadtime(15)
	{
	}
	//총알 방향성
	void direction(bool player_move)
	{
		bullet_move = player_move;
	}

	void draw()
	{
		if (isFiring == false) return;
		screen->draw(pos, face);
	}

	void update(int enemy_pos)
	{
		if (isFiring == false) {
			return;
		}
		int pos = getPosition();
		if (bullet_move) {
			pos += 1;
		}
		else if (bullet_move == false) {
			pos -= 1;
		}
		if (pos > enemy_pos - 1 && pos < enemy_pos + 5) {
			isFiring = false;
			hit = true;
		}
		else if (pos == screen->length())
			isFiring = false;
		setPosition(pos);
	}
	//사격
	void fire(int player_pos, int bullet_num)
	{
		if (bullet_num == 10)return; //총알 10발 다 쐈을 때 사격못함
		isFiring = true;
		setPosition(player_pos + 3);
	}
	//데미지
	int damage(int enemy_life)
	{
		if (hit == false)return enemy_life;
		hit = false;
		enemy_life -= 1;
		return enemy_life;
	}
	//장전
	int reloading()
	{
		if (reload)
			reloadtime--;
		if (reloadtime == 0)
		{
			reloadtime = 15;
			return -1;
		}
		else
			return 0;
	}
	void reload_on()
	{
		reload = true;
	}
	void reload_off()
	{
		reload = false;
		reloadtime = 15;
	}
	int reload_time()
	{
		return reloadtime;
	}
	int do_fire()
	{
		return isFiring;
	}
};

class Laser_Bullet : public GameObject
{
	bool isFiring;
	bool bullet_move;
	bool can_fire;
	int startpos;
	int cooltime;
	int shoottime;
	int hittime;
	int p_facelen;
	int e_facelen;
	int remain_cooltime;
	int remain_shoottime;

public:
	Laser_Bullet(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen), isFiring(false), can_fire(true), bullet_move(true),
		cooltime(0), p_facelen(6), e_facelen(4), remain_cooltime(3), remain_shoottime(2)
	{
	}
	//방향성
	void direction(bool player_move)
	{
		bullet_move = player_move;
	}

	void draw(int enemy_pos, int player_pos, int length)
	{
		if (isFiring == false)return;
		if (bullet_move) {
			//오른쪽에 적이 없을 경우
			if (enemy_pos < player_pos) {
				startpos = player_pos + p_facelen;
				for (int i = 0; i < (length - 1) - startpos; i++)
				{
					screen->draw(startpos + i, "@");
				}
			}
			//오른쪽에 적이 있을 경우
			else {
				if (hittime > 15) {
					hittime = 0;
				}
				hittime++;
				startpos = player_pos + p_facelen;
				for (int i = 0; i < enemy_pos - startpos; i++)
				{
					screen->draw(startpos + i, "@");
				}
			}
		}
		if (bullet_move == false) {
			//왼쪽에 적이 없을 경우
			if (enemy_pos > player_pos) {
				startpos = player_pos - 1;
				for (int i = 0; i < startpos - 1; i++)
				{
					screen->draw(startpos - i, "@");
				}
			}
			//왼쪽에 적이 있을 경우
			else {
				if (hittime > 15) {
					hittime = 0;
				}
				hittime++;
				startpos = player_pos - 1;
				for (int i = 0; i < startpos - enemy_pos - e_facelen; i++)
				{
					screen->draw(startpos - i, "@");
				}
			}
		}
	}

	void update()
	{
		if (isFiring == false) {
			cooltime--;
			shoottime = 30;
			return;
		}
		shoottime--;
		if (shoottime < 0) {
			isFiring = false;
			shoottime = 32;
			cooltime = 45;
			hittime = 0;
		}
		setPosition(pos);
	}
	//사격
	void fire(int player_pos, int enemy_pos)
	{
		if (cooltime < 1) {
			isFiring = true;
			setPosition(player_pos);
		}
	}
	//데미지
	int hit_time()
	{
		return hittime;
	}

	int do_fire()
	{
		return isFiring;
	}

	int shoot_time()
	{
		remain_shoottime = shoottime / 15;
		return remain_shoottime;
	}

	int cool_time()
	{
		remain_cooltime = cooltime / 15;
		return remain_cooltime;
	}
};

class Information :public GameObject
{
	char plus1[10];
	char plus2[10];
	char player_print[5];
	int playerstatus_pos;
	int reloadtime;
	bool print;
	bool player;
	bool bullet;
	bool laser;
public:
	Information(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen), print(false), player(false), bullet(false), laser(false)
	{}

	void print_player_life(int player_life, int player_pos, bool player_move, bool poison)
	{
		if (poison) {
			if (player_move)
				playerstatus_pos = player_pos - 2;
			else
				playerstatus_pos = player_pos + 6;
			_itoa(player_life, player_print, 10);
			player = true;
		}
	}

	void print_bullet(bool weapon, bool direction, bool fire, int bulletnum, int player_pos, int time)
	{
		if (weapon) {
			if (fire)print = true;
			if (print) {
				strcpy(face, "gun,");
				_itoa(bulletnum, plus1, 10);
				reloadtime = bulletnum;
				_itoa(reloadtime, plus2, 10);
				strcat(face, plus1);
				strcat(face, ", ");
				strcat(face, plus2);
				if (direction)
					setPosition(player_pos - 9);
				else
					setPosition(player_pos + 6);
				if (time > 0)
					bullet = true;
			}
		}
	}

	void print_laser(bool weapon, bool direction, bool fire, int shoottime, int cooltime, int player_pos, int time)
	{
		if (weapon == false) {
			if (fire)print = true;
			if (print) {
				strcpy(face, "laser,");
				_itoa(shoottime, plus1, 10);
				_itoa(cooltime, plus2, 10);
				strcat(face, plus1);
				strcat(face, ", ");
				strcat(face, plus2);
				if (direction)
					setPosition(player_pos - 9);
				else
					setPosition(player_pos + 6);
				if (time > 0)
					laser = true;
			}
		}
	}

	void draw()
	{
		if (bullet == true || laser == true) {
			screen->draw(pos, face);
			bullet = false;
			laser = false;
		}
		if (player) {
			screen->draw(playerstatus_pos, player_print);
			player = false;
		}
	}
};

int main()
{
	Screen screen{ 80 };
	Player player{ 40, "[[^_^)", &screen , "(^_^]]" ,10 };
	Enemy enemy{ -10, "(*_*)", &screen, 5 };
	Bullet * bullet[11];
	Laser_Bullet l_bullet{ -1, "@", &screen };
	Information info{ -10, "", &screen };

	//bullet[10]은 재장전
	for (int i = 0; i < 11; i++)
	{
		bullet[i] = new Bullet{ -1, "+", &screen };
	}
	int bullet_num = 0;
	int screentime = 15;
	bool gun_weapon = true;
	bool go_time = false;

	while (true)
	{
		screen.clear();
		if (_kbhit())
		{
			int c = _getch();
			switch (c) {
			case 'a':
				player.moveLeft();
				l_bullet.direction(player.player_moveRight()); //레이저 방향성
				break;
			case 'd':
				player.moveRight();
				l_bullet.direction(player.player_moveRight()); //레이저 방향성
				break;
			case'm':
				if (gun_weapon)
					gun_weapon = false;
				else
					gun_weapon = true;
				break;
			case ' ':
				if (bullet_num < 10) {
					if (gun_weapon) {
						bullet[bullet_num]->fire(player.getPosition(), bullet_num);
						bullet[bullet_num]->direction(player.player_moveRight());
						go_time = true;
						screentime = 15;
						bullet_num += 1;
						bullet[10]->reload_off();
					}
				}
				if (gun_weapon == false) {
					l_bullet.fire(player.getPosition(), enemy.getPosition());
					go_time = true;
					screentime = 15;
				}
				break;
			}
		}
		//무기상태창
		if (go_time)
			screentime--;
		for (int i = 0; i < 10; i++)
			info.print_bullet(gun_weapon, player.player_moveRight(), bullet[i]->do_fire(), bullet_num, player.getPosition(), screentime);
		info.print_laser(gun_weapon, player.player_moveRight(), l_bullet.do_fire(), l_bullet.shoot_time(), l_bullet.cool_time(), player.getPosition(), screentime);
		//총알 재장전
		if (bullet_num == 10) {
			bullet[10]->reload_on();
		}
		//그리기
		player.draw();
		enemy.draw();
		info.draw();
		if (gun_weapon) {
			for (int i = 0; i < 10; i++)
				bullet[i]->draw();
		}
		else
			l_bullet.draw(enemy.getPosition(), player.getPosition(), screen.length());
		//업데이트
		if (gun_weapon) {
			for (int i = 0; i < 10; i++)
			{
				enemy.check_life(bullet[i]->damage(enemy.how_life()));
				bullet[i]->update(enemy.getPosition());
			}
		}
		else {
			l_bullet.update();
		}
		enemy.update(l_bullet.hit_time(), player.getPosition());
		player.update(enemy.getPosition());
		info.print_player_life(player.how_life(), player.getPosition(), player.player_moveRight(), player.poison_status());
		bullet_num += bullet[10]->reloading();
		screen.render();
		Sleep(66);
	}

	return 0;
}