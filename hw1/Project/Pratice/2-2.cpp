//2020-03-30 
//Create HotPotato Game
//use circle queue of C++

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#define MAXSIZE 8

#pragma region CircleQueue
typedef struct CircleQueue {
	int front;
	int rear;
	int Max;
	string Data[MAXSIZE];
}CQ;

void InitializeCQ(CQ& q, int num) {

	q.front = -1;
	q.rear = -1;
	q.Max = num;
}

bool IsCQEmpty(CQ& q) {

	if (q.front == -1 && q.rear == -1)
		return true;
	else
		return false;
}

bool IsCQFull(CQ& q) {

	if ((q.rear + 1) % q.Max == q.front)
		return true;
	else
		return false;
}

void Enqueue(CQ& q, string x) {
	if (IsCQFull(q)) {
		cout << "Is full!" << endl;;
		exit(1);
	}

	if (IsCQEmpty(q)) {
		q.front = 0;
		q.rear = 0;
		q.Data[q.rear] = x;
	}

	else {
		q.rear = (q.rear + 1) % q.Max;
		q.Data[q.rear] = x;
	}
}

string Dequeue(CQ& q) {
	string temp;

	if (IsCQEmpty(q)) {
		cout << "Is empty!" << endl;
		exit(1);
	}

	temp = q.Data[q.front];

	if (q.front == q.rear) {
		q.front = -1;
		q.rear = -1;
	}
	else
		q.front = (q.front + 1) % q.Max;

	return temp;
}

string Peek(CQ& q) {

	if (IsCQEmpty(q)) {
		cout << "Is empty!" << endl;
		exit(1);
	}

	return (q.Data[q.front]);
}

void PrintCQ(CQ& q) {

	if (IsCQEmpty(q)) {
		cout << "Is empty!" << endl;
		exit(1);
	}

	if (q.front <= q.rear) {
		for (int i = q.front; i <= q.rear; i++)
			cout << q.Data[i] << " ";
	}

	else {
		for (int i = q.front; i <= q.rear + q.Max; i++)
			cout << q.Data[i%q.Max] << " ";
	}
	cout << endl;
}

int CountCQ(CQ& q) {

	int num = 0;

	if (IsCQEmpty(q)) {
		cout << "Is empty!" << endl;
		exit(1);
	}

	if (q.front <= q.rear) {
		for (int i = q.front; i <= q.rear; i++)
			num++;
	}

	else {
		for (int i = q.front; i <= q.rear + q.Max; i++)
			num++;
	}

	return num;
}
#pragma endregion

int SizeOfStringArray(string (&st)[8])					//return string[] length
{
	int result = 0;

	for (int i = 0; i < sizeof(st) / sizeof(string); i++)
		if (st[i].size() > 0)
			result++;

	return result;
}

template<typename T>
string HotPotato(T &player_list, int num)
{
	int playersNum;

	CQ players;
	InitializeCQ(players, SizeOfStringArray(player_list));

	for (int i = 0; i < SizeOfStringArray(player_list); i++)		//put player_list in circlequeue players
		Enqueue(players, player_list[i]);

	playersNum = players.Max;

	while (playersNum > 1)											//run until one is left
	{
		int repeatNum = num;
		while (repeatNum != 0)										//repeat by num
		{
			string getPotato_player = Dequeue(players);
			Enqueue(players, getPotato_player);

			repeatNum--;
		}

		cout << Dequeue(players) << " is out" << endl;		//print out players
		playersNum--;
	}

	return Dequeue(players);										//winner
}


int main()
{
	string player_list[8];

	int player_num;
	int rotate_PotatoNum;

	cout << "How many players play game? : ";
	cin >> player_num;																	//input player num

	cout << "- Input player -" << endl;
	
	for (int i = 0; i < player_num; i++)												//input player
		cin >> player_list[i];

	srand(time(NULL));
	rotate_PotatoNum = rand() % 16 + 5;											//input random num

	cout << "Rotate Num is " << rotate_PotatoNum << endl;

	cout << "Winner is " << HotPotato(player_list, rotate_PotatoNum);		//play the game

	return 0;
}