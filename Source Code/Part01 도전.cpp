//part1 ���� ���α׷��� ����
#include <iostream>
#include <cmath>

using namespace std;

//10������ 16������ ���
void question_1()
{
	int num;

	cout << "������ �Է��Ͻÿ�(16������ ���) : ";
	cin >> num;

	//c++
	//cout << num << "�� 16���� : " << hex << num << oct << endl << endl;
	//c
	printf("%d�� 16���� : %x\n\n", num, num);

	return;
}

//�� ������ �Է¹޾� �� ������ ������ �� ���� ���̿� �ִ� ���ڵ��� ������ ���
void question_2()
{
	int num1, num2;

	cout << "���� �� ���� �Է��Ͻÿ�(�� ���� ���̰� ������ ���)" << endl;
	cin >> num1 >> num2;

	//���׿����ڸ� �̿��� num1�� num2�� ũ��� ������� ũ�Ⱑ ���� �� ���� ���
	for (int i = (num1 > num2 ? num2 : num1); i <= (num1 > num2 ? num1 : num2); i++)
		for (int j = 1; j < 10; j++)
			cout << i << "X" << j << " = " << i * j << endl;

	cout << endl;
}

//�� ������ �Է¹޾� �� ������ �ִ� ����� ���
void question_3()
{
	int num1, num2;

	cout << "���� �� ���� �Է��Ͻÿ�(�ִ� ����� ���)" << endl;
	cin >> num1 >> num2;

	//���׿����ڸ� �̿��� ���� ���ڿ� ū �� �ֱ�
	int first_num = num1 > num2 ? num1 : num2;
	int second_num = num1 > num2 ? num2 : num1;
	int remain = 1;

	//��Ŭ���� ȣ����
	while (remain != 0)
	{
		remain = first_num % second_num;
		first_num = second_num;
		second_num = remain;
	}

	cout << num1 << "�� " << num2 << "�� �ִ� ������� : " << first_num << endl << endl;

	return;
}

//3500������ �ܵ��� ������ �ʰ� ũ����(500��), �����(700��), �ݶ�(400��)�� �ϳ� �̻� �����ϴ� ��� ����� �� ���
void question_4()
{
	int remainMoney = 3500;
	int creamBread_pay = 500;
	int shrimpSnack_pay = 700;
	int cola_pay = 400;

	cout << "���� �� : " << remainMoney << endl;

	for (int creamBread = 1; creamBread <= (remainMoney - (shrimpSnack_pay + cola_pay)) / creamBread_pay; creamBread++)
	{
		for (int shrimpSnack = 1; shrimpSnack <= (remainMoney - (creamBread_pay + cola_pay)) / shrimpSnack_pay; shrimpSnack++)
		{
			for (int cola = 1; cola <= (remainMoney - (shrimpSnack_pay + creamBread_pay)) / cola_pay; cola++)
			{
				if ((creamBread*creamBread_pay + shrimpSnack * shrimpSnack_pay + cola * cola_pay) == remainMoney)
				{
					printf("ũ���� %d��, ����� %d��, �ݶ� %d��\n", creamBread, shrimpSnack, cola);
				}
			}
		}
	}

	cout << "��� �����Ͻðڽ��ϱ�?" << endl << endl;
}

//10���� �Ҽ� ���
void question_5()
{
	int print_num = 0;
	int num = 2;

	while (print_num < 10)
	{
		bool decimal = true;

		for (int i = 2; i <= num; i++)
		{
			if (num%i == 0 && num != i)
			{
				decimal = false;
				break;
			}
		}

		if (decimal)
		{
			cout << num << " ";
			print_num++;
		}

		num++;
	}

	cout << endl << endl;
}

//�ʸ� �Է¹޾� ��, ��, �� ���·� ���
void question_6()
{
	int hour, minute, second;

	cout << "��(second)�� �Է��Ͻÿ� : ";
	cin >> second;

	hour = second / 60 / 60;
	minute = (second / 60) % 60;
	second = second % 60;

	printf("�� : %d, �� : %d, �� : %d\n\n", hour, minute, second);
}

//���� n�� �Է� �޾� (2^k<=n)�� �����ϴ� k�� �ִ밪 ���
void question_7()
{
	int n;
	int k = 0;
	int result = 1;

	cout << "2^k<=n�� n�� �Է��Ͻÿ� : ";
	cin >> n;

	while (result < n)
	{
		result = 1;
		for (int i = 1; i <= k; i++)
		{
			result *= 2;
		}

		k++;
	}

	if (result == n) cout << "������ �����ϴ� k�� �ִ��� : " << k - 1;
	else cout << "������ �����ϴ� k�� �ִ��� : " << k - 2;

	cout << endl << endl;
	return;
}

//2�� n�� ���ϴ� �Լ�
int powOf2(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 2;
	return 2 * powOf2(n - 1);
}

//n�� �Է¹޾� 2�� n���� ���
void question_8()
{
	int n;

	cout << "������ �Է��Ͻÿ� : ";
	cin >> n;

	printf("2�� %d���� : %d\n\n", n, powOf2(n));

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

		case 4:
			question_4();
			break;

		case 5:
			question_5();
			break;

		case 6:
			question_6();
			break;

		case 7:
			question_7();
			break;

		case 8:
			question_8();
			break;
		}

	}

	return 0;
}