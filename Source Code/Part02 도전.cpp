//part2 도전 프로그래밍 문제
#include <iostream>
#include <cmath>

using namespace std;

//홀수 출력
void PrintOdd(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 1)printf("%d ", arr[i]);
}

//짝수 출력
void PrintEven(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 0)printf("%d ", arr[i]);
}

//10개의 정수를 입력받아 홀수, 짝수를 구분하여 출력
void question_1()
{
	int arr[10];

	cout << "10개의 정수를 입력하시오" << endl;
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	cout << "홀수 출력 : ";
	PrintOdd(arr, 10);
	cout << endl;

	cout << "짝수 출력 : ";
	PrintEven(arr, 10);
	cout << endl << endl;

	return;
}

//10진수 -> 2진수
void ChangeDecimalToBinary(int num)
{
	int arr[10] = { 0, };
	int end_index = 0;

	//num을 입력받아 배열 arr에 넣기
	for (int i = 0; i < 10; i++)
	{
		if (num == 1 || num == 0)
		{
			arr[i] = num;
			break;
		}
		arr[i] = num % 2;
		num /= 2;
		end_index++;
	}

	//arr끝에서 부터 출력
	for (int i = end_index; i >= 0; i--)
		cout << arr[i];

	return;
}

//10진수 정수를 하나 입력받은 후 2진수로 출력
void question_2()
{
	int num;

	cout << "정수를 입력하시오(2진수 변환) : ";
	cin >> num;

	cout << "2진수 : ";
	ChangeDecimalToBinary(num);

	cout << endl << endl;

	return;
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//10개의 정수를 입력받아 홀수를 앞으로 짝수를 뒤로 배열에 저장 후 출력
void question_3()
{
	int arr[10];
	int temp[10];

	cout << "10개의 정수를 입력하시오" << endl;
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	int temp_firstIndex = 0;
	int temp_lastIndex = 9;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 1)
			temp[temp_firstIndex++] = arr[i];
		else
			temp[temp_lastIndex--] = arr[i];
	}

	for (int i = 0; i < 10; i++)
		arr[i] = temp[i];

	cout << "배열 출력 : ";

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	cout << endl << endl;

	return;
}

//회문
void IsPalindrome(char word[])
{
	bool yes = true;

	int j = strlen(word) - 1;
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] != word[j])
		{
			yes = false;
			break;
		}

		j--;
	}

	if (yes == true)
		cout << "회문입니다." << endl;
	else
		cout << "회문이 아닙니다." << endl;

	return;
}

//회문 출력
void question_4()
{
	char word[10];

	cout << "문자를 입력하시오 : ";
	cin >> word;

	IsPalindrome(word);

	cout << endl;
}

//버블 정렬(내림차순)
void DesSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] < arr[j]) Swap(&arr[i], &arr[j]);
		}
	}

	return;
}

//버블 정렬 출력
void question_5()
{
	int arr[7];

	cout << "정수를 입력하시오(내림차순 정렬)" << endl;
	for (int i = 0; i < 7; i++)
		cin >> arr[i];

	DesSort(arr, 7);

	cout << "배열 출력 : ";

	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	cout << endl << endl;
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