#include <iostream>

using namespace std;

void question_1()
{
	int num1;
	int num2;
	int sum = 0;

	cout << "�� ���� ������ �Է��Ͻÿ�(���� ���� ��) " << endl;
	cin >> num1;
	cin >> num2;
	
	for (; num1 > num2;)
	{
		cout << "�ڿ� ���ڰ� �� �۽��ϴ�. �ٽ� �Է��Ͻÿ�" << endl;
		cin >> num1;
		cin >> num2;
	}

	for (int i = num1; i <= num2; i++) 	sum += i;

	cout << "�� ���� ������ ���� ���� : " << sum << endl << endl;

	return;
}

void question_2()
{
	int num;
	int sum = 1;

	cout << "������ �Է��Ͻÿ�(factorial) " << endl;
	cin >> num;

	for (int i = 1; i <= num; i++) sum *= i;

	cout << "factorial ���� : " << sum << endl << endl;

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
		}

	}

	return 0;
}