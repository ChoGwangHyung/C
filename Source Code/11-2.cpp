//배열기반의 문자열 표현
#include <iostream>

using namespace std;

//하나의 영단어를 입력받아 영단어의 길이를 계산하여 출력
void question_1()
{
	char arr[10];
	int size = 0;

	cout << "영단어를 입력하시오 :  ";
	cin >> arr;

	for (int i = 0; arr[i] != NULL; i++)
		size++;

	cout << "영단어를 받은 배열의 길이는 : " << size << endl << endl;

	return;
}

//영단어를 입력받아 역순으로 뒤집기
void question_2()
{
	char arr[10];
	char reverse[10] = { NULL, };
	int size = 0;

	cout << "영단어를 입력하시오 :  ";
	cin >> arr;

	for (int i = 0; arr[i] != NULL; i++)
		size++;

	for (int i = 0; i < size; i++)
		reverse[i] = arr[size - i - 1];

	cout << "입력받은 영단어의 역순은 : " << reverse << endl << endl;

	return;
}

//영단어를 입력받아 아스키코드 값이 가장 큰 문자 출력
void question_3()
{
	char arr[10];
	char result;

	cout << "영단어를 입력하시오 :  ";
	cin >> arr;

	result = arr[0];

	for (int i = 1; arr[i] != NULL; i++)
		if (result < arr[i]) result = arr[i];

	cout << "아스키 코드 값이 가장 큰 문자는 : " << result << endl << endl;

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