//2���� �迭�� Ȱ��
#include <iostream>

using namespace std;

//���� 9 ���� 3�� int�� 2���� �迭�� �����Ͽ� ������ �� 2, 3, 4���� ����
void question_1()
{
	int arr[3][9];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 9; j++)
			arr[i][j] = (i + 2)*(j + 1);

	for (int i = 0; i < 3; i++)
	{
		cout << i + 2 << "�� : ";
		for (int j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);

		cout << endl;
	}

	cout << endl;

	return;
}

//���� 4 ���� 2�� 2���� �迭�� ����� ���ÿ� �ʱ�ȭ �� �� �迭�� �̿��� ���� 2 ���� 4�� 2���� �迭�� �ʱ�ȭ
void question_2()
{
	char a[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
	char b[4][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			b[j][i] = a[i][j];

	cout << "B �迭" << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%d ", b[i][j]);

		cout << endl;
	}

	cout << endl << endl;

	return;
}

//4����� 4������ ������ �޾� ���� ���(�������� ���α׷�)
void question_3()
{
	int scoreBoard[5][5] = { {0,}, };		

	for (int i = 0; i < 4; i++)
	{
		switch (i) 
		{
		case 0:
			cout << "ö���� ������ �Է��Ͻÿ�" << endl;
			break;
		case 1:
			cout << "ö���� ������ �Է��Ͻÿ�" << endl;
			break;
		case 2:
			cout << "������ ������ �Է��Ͻÿ�" << endl;
			break;
		case 3:
			cout << "������ ������ �Է��Ͻÿ�" << endl;
			break;
		}

		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 0:
				cout << "���� : ";
				break;
			case 1:
				cout << "���� : ";
				break;
			case 2:
				cout << "���� : ";
				break;
			case 3:
				cout << "���� : ";
				break;
			}	

			cin >> scoreBoard[i][j];
			
			//���� ����
			scoreBoard[4][j] += scoreBoard[i][j];
			//���κ� ����
			scoreBoard[i][4] += scoreBoard[i][j];			
		}

		//���κ� ��ü ����
		scoreBoard[4][4] += scoreBoard[i][4];

		cout << endl;
	}

	printf("\t\t����\t����\t����\t����\t����\n");

	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0:
			printf("ö��\t\t");
			break;
		case 1:
			printf("ö��\t\t");
			break;
		case 2:
			printf("����\t\t");
			break;
		case 3:
			printf("����\t\t");
			break;
		case 4:
			printf("���� ����\t");
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