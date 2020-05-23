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

	cout << "�� ���� ������ �Է��Ͻÿ�." << endl;

	for (int i = 0; i < 3; i++) cin>>num[i];

	cout << "���� ū ���ڴ� : " << Print_Max(num) << endl;

	cout << "���� ���� ���ڴ� : " << Print_Min(num) << endl;

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

	cout << "���� �µ��� �Է��Ͻÿ� : ";
	cin >> num;
	cout << "���� -> ȭ�� : " << CelToFah(num) << endl;

	cout << "ȭ�� �µ��� �Է��Ͻÿ� : ";
	cin >> num;
	cout << "ȭ�� -> ���� : " << FahToCel(num) << endl;

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

	cout << "������ �Է��Ͻÿ�.(�Ǻ���ġ ����) : ";
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
		cout << "�� �� ������ ���ðڽ��ϱ�?(0�� �Է��ϸ� ����)" << endl;
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