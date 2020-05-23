#include <iostream>

using namespace std;

void question_1()
{
	int num;

	cout << "양의 정수를 입력하시오 :  ";
	cin >> num;

	while (num > 0)
	{
		cout << "Hello wolrd!" << endl;
		num--;
	}

	cout << endl;

	return;
}

void question_2()
{
	int num;

	cout << "양의 정수를 입력하시오(3의 배수 출력) : ";
	cin >> num;

	int i = 1;

	while (i <= num)
	{
		cout << 3 * i++;
		cout << " ";
	}

	cout << endl << endl;

	return;
}

void question_3()
{
	int num = 1;
	int sum = 0;

	while (num != 0)
	{
		cout << "양의 정수를 입력하시오(덧셈, 0을 입력하면 종료)" << endl;
		cin >> num;

		sum += num;
	}

	cout << "입력된 정수의 총합은 : " << sum << endl << endl;

	return;
}

void question_4()
{
	int num;

	cout << "양의 정수를 입력하시오(구구단 역순 출력) : ";
	cin >> num;

	int i = 9;

	while (i > 0)
	{
		cout << num << "X" << i << " = " << num * i << " ";
		i--;
	}

	cout << endl << endl;;

	return;
}

void question_5()
{
	int num;
	float sum = 0;

	cout << "몇 개의 정수를 입력하시겠습니까?(평균) : ";
	cin >> num;

	cout << "정수를 입력하시오" << endl;

	int i = num;

	while (i > 0)
	{
		int input;
		cin >> input;

		sum += input;

		i--;
	}

	cout << "평균은 : " << sum / num << endl << endl;

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

		case 4:
			question_4();
			break;

		case 5:
			question_5();
			break;
		}

	}

	return 0;
}