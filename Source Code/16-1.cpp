//2차원 배열의 활용
#include <iostream>

using namespace std;

//가로 9 세로 3인 int형 2차원 배열을 선언하여 구구단 중 2, 3, 4단을 저장
void question_1()
{
	int arr[3][9];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 9; j++)
			arr[i][j] = (i + 2)*(j + 1);

	for (int i = 0; i < 3; i++)
	{
		cout << i + 2 << "단 : ";
		for (int j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);

		cout << endl;
	}

	cout << endl;

	return;
}

//가로 4 세로 2의 2차원 배열을 선언과 동시에 초기화 후 이 배열을 이용해 가로 2 세로 4의 2차원 배열을 초기화
void question_2()
{
	char a[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
	char b[4][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			b[j][i] = a[i][j];

	cout << "B 배열" << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%d ", b[i][j]);

		cout << endl;
	}

	cout << endl << endl;

	return;
}

//4사람의 4과목의 점수를 받아 총점 출력(성적관리 프로그램)
void question_3()
{
	int scoreBoard[5][5] = { {0,}, };		

	for (int i = 0; i < 4; i++)
	{
		switch (i) 
		{
		case 0:
			cout << "철희의 점수를 입력하시오" << endl;
			break;
		case 1:
			cout << "철수의 점수를 입력하시오" << endl;
			break;
		case 2:
			cout << "영희의 점수를 입력하시오" << endl;
			break;
		case 3:
			cout << "영수의 점수를 입력하시오" << endl;
			break;
		}

		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 0:
				cout << "국어 : ";
				break;
			case 1:
				cout << "영어 : ";
				break;
			case 2:
				cout << "수학 : ";
				break;
			case 3:
				cout << "국사 : ";
				break;
			}	

			cin >> scoreBoard[i][j];
			
			//과목별 총점
			scoreBoard[4][j] += scoreBoard[i][j];
			//개인별 총점
			scoreBoard[i][4] += scoreBoard[i][j];			
		}

		//개인별 전체 총점
		scoreBoard[4][4] += scoreBoard[i][4];

		cout << endl;
	}

	printf("\t\t국어\t영어\t수학\t국사\t총점\n");

	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0:
			printf("철희\t\t");
			break;
		case 1:
			printf("철수\t\t");
			break;
		case 2:
			printf("영희\t\t");
			break;
		case 3:
			printf("영수\t\t");
			break;
		case 4:
			printf("과목별 총점\t");
			break;
		}

		for (int j = 0; j < 5; j++)
			printf("%d\t", scoreBoard[i][j]);

		cout << endl;
	}

	cout << endl;

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