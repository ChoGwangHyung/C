#include <iostream>

using namespace std;

void question_1()
{
	int num1;
	int num2;
	int sum = 0;

	cout << "두 개의 정수를 입력하시오(사이 값의 합) " << endl;
	cin >> num1;
	cin >> num2;
	
	for (; num1 > num2;)
	{
		cout << "뒤에 숫자가 더 작습니다. 다시 입력하시오" << endl;
		cin >> num1;
		cin >> num2;
	}

	for (int i = num1; i <= num2; i++) 	sum += i;

	cout << "두 정수 사이의 값의 합은 : " << sum << endl << endl;

	return;
}

void question_2()
{
	int num;
	int sum = 1;

	cout << "정수를 입력하시오(factorial) " << endl;
	cin >> num;

	for (int i = 1; i <= num; i++) sum *= i;

	cout << "factorial 값은 : " << sum << endl << endl;

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
		}

	}

	return 0;
}