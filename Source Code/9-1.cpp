#include <iostream>

using namespace std;

int Print_Max(int num[3])
{
	int max = num[0];
	
	for (int i = 1; i < 3; i++)
		if (max < num[i]) max = num[i];

	return max;
}

int Print_Min(int num[3])
{
	int min = num[0];

	for (int i = 1; i < 3; i++)
		if (min > num[i]) min = num[i];

	return min;
}

void question_1()
{
	int num[3];

	cout << "세 개의 정수를 입력하시오." << endl;

	for (int i = 0; i < 3; i++) cin>>num[i];

	cout << "제일 큰 숫자는 : " << Print_Max(num) << endl;

	cout << "제일 작은 숫자는 : " << Print_Min(num) << endl;

	cout << endl;

	return;
}

float CelToFah(float cel)
{
	return 1.8*cel + 32;
}

float FahToCel(float fah)
{
	return (fah - 32) / 1.8;
}

void question_2()
{
	int num;

	cout << "섭씨 온도를 입력하시오 : ";
	cin >> num;
	cout << "섭씨 -> 화씨 : " << CelToFah(num) << endl;

	cout << "화씨 온도를 입력하시오 : ";
	cin >> num;
	cout << "화씨 -> 섭씨 : " << FahToCel(num) << endl;

	cout << endl;

	return;
}

int Fibo(int num)
{
	if (num == 1) return 0;
	else if (num == 2) return 1;
	else return Fibo(num - 1) + Fibo(num - 2);	
}

void question_3()
{
	int num;

	cout << "정수를 입력하시오.(피보나치 수열) : ";
	cin >> num;

	for (int i = 1; i <= num; i++) cout << Fibo(i) << " ";
	
	cout << endl << endl;

	return;
}

int main()
{
	int what_question;

	while (true)
	{
		cout << "몇 번 문제를 보시겠습니까?(0을 입력하면 종료)" << endl;
		cin >> what_question;

		cout << endl;

		switch (what_question)
		{
		case 0:
			return 0;

		case 1:
			question_1();
			break;

		case 2:
			question_2();
			break;

		case 3:
			question_3();
			break;
		}

	}

	return 0;
}