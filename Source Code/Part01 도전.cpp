//part1 도전 프로그래밍 문제
#include <iostream>
#include <cmath>

using namespace std;

//10진수를 16진수로 출력
void question_1()
{
	int num;

	cout << "정수를 입력하시오(16진수로 출력) : ";
	cin >> num;

	//c++
	//cout << num << "의 16진수 : " << hex << num << oct << endl << endl;
	//c
	printf("%d의 16진수 : %x\n\n", num, num);

	return;
}

//두 정수를 입력받아 두 정수를 포함한 두 정수 사이에 있는 숫자들의 구구단 출력
void question_2()
{
	int num1, num2;

	cout << "정수 두 개를 입력하시오(두 정수 사이값 구구단 출력)" << endl;
	cin >> num1 >> num2;

	//삼항연산자를 이용해 num1과 num2의 크기와 상관없이 크기가 작은 순 먼저 출력
	for (int i = (num1 > num2 ? num2 : num1); i <= (num1 > num2 ? num1 : num2); i++)
		for (int j = 1; j < 10; j++)
			cout << i << "X" << j << " = " << i * j << endl;

	cout << endl;
}

//두 정수를 입력받아 두 정수의 최대 공약수 출력
void question_3()
{
	int num1, num2;

	cout << "정수 두 개를 입력하시오(최대 공약수 출력)" << endl;
	cin >> num1 >> num2;

	//삼항연산자를 이용해 나눌 숫자에 큰 값 넣기
	int first_num = num1 > num2 ? num1 : num2;
	int second_num = num1 > num2 ? num2 : num1;
	int remain = 1;

	//유클리드 호제법
	while (remain != 0)
	{
		remain = first_num % second_num;
		first_num = second_num;
		second_num = remain;
	}

	cout << num1 << "과 " << num2 << "의 최대 공약수는 : " << first_num << endl << endl;

	return;
}

//3500원으로 잔돈을 남기지 않고 크림빵(500원), 새우깡(700원), 콜라(400원)을 하나 이상 구매하는 모든 경우의 수 출력
void question_4()
{
	int remainMoney = 3500;
	int creamBread_pay = 500;
	int shrimpSnack_pay = 700;
	int cola_pay = 400;

	cout << "남은 돈 : " << remainMoney << endl;

	for (int creamBread = 1; creamBread <= (remainMoney - (shrimpSnack_pay + cola_pay)) / creamBread_pay; creamBread++)
	{
		for (int shrimpSnack = 1; shrimpSnack <= (remainMoney - (creamBread_pay + cola_pay)) / shrimpSnack_pay; shrimpSnack++)
		{
			for (int cola = 1; cola <= (remainMoney - (shrimpSnack_pay + creamBread_pay)) / cola_pay; cola++)
			{
				if ((creamBread*creamBread_pay + shrimpSnack * shrimpSnack_pay + cola * cola_pay) == remainMoney)
				{
					printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", creamBread, shrimpSnack, cola);
				}
			}
		}
	}

	cout << "어떻게 구입하시겠습니까?" << endl << endl;
}

//10개의 소수 출력
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

//초를 입력받아 시, 분, 초 형태로 출력
void question_6()
{
	int hour, minute, second;

	cout << "초(second)를 입력하시오 : ";
	cin >> second;

	hour = second / 60 / 60;
	minute = (second / 60) % 60;
	second = second % 60;

	printf("시 : %d, 분 : %d, 초 : %d\n\n", hour, minute, second);
}

//숫자 n을 입력 받아 (2^k<=n)이 성립하는 k의 최대값 출력
void question_7()
{
	int n;
	int k = 0;
	int result = 1;

	cout << "2^k<=n의 n을 입력하시오 : ";
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

	if (result == n) cout << "공식을 만족하는 k의 최댓값은 : " << k - 1;
	else cout << "공식을 만족하는 k의 최댓값은 : " << k - 2;

	cout << endl << endl;
	return;
}

//2의 n승 구하는 함수
int powOf2(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 2;
	return 2 * powOf2(n - 1);
}

//n을 입력받아 2의 n승을 출력
void question_8()
{
	int n;

	cout << "정수를 입력하시오 : ";
	cin >> n;

	printf("2의 %d승은 : %d\n\n", n, powOf2(n));

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