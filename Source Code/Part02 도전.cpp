//part2 ���� ���α׷��� ����
#include <iostream>
#include <cmath>

using namespace std;

//Ȧ�� ���
void PrintOdd(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 1)printf("%d ", arr[i]);
}

//¦�� ���
void PrintEven(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 0)printf("%d ", arr[i]);
}

//10���� ������ �Է¹޾� Ȧ��, ¦���� �����Ͽ� ���
void question_1()
{
	int arr[10];

	cout << "10���� ������ �Է��Ͻÿ�" << endl;
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	cout << "Ȧ�� ��� : ";
	PrintOdd(arr, 10);
	cout << endl;

	cout << "¦�� ��� : ";
	PrintEven(arr, 10);
	cout << endl << endl;

	return;
}

//10���� -> 2����
void ChangeDecimalToBinary(int num)
{
	int arr[10] = { 0, };
	int end_index = 0;

	//num�� �Է¹޾� �迭 arr�� �ֱ�
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

	//arr������ ���� ���
	for (int i = end_index; i >= 0; i--)
		cout << arr[i];

	return;
}

//10���� ������ �ϳ� �Է¹��� �� 2������ ���
void question_2()
{
	int num;

	cout << "������ �Է��Ͻÿ�(2���� ��ȯ) : ";
	cin >> num;

	cout << "2���� : ";
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

//10���� ������ �Է¹޾� Ȧ���� ������ ¦���� �ڷ� �迭�� ���� �� ���
void question_3()
{
	int arr[10];
	int temp[10];

	cout << "10���� ������ �Է��Ͻÿ�" << endl;
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

	cout << "�迭 ��� : ";

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	cout << endl << endl;

	return;
}

//ȸ��
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
		cout << "ȸ���Դϴ�." << endl;
	else
		cout << "ȸ���� �ƴմϴ�." << endl;

	return;
}

//ȸ�� ���
void question_4()
{
	char word[10];

	cout << "���ڸ� �Է��Ͻÿ� : ";
	cin >> word;

	IsPalindrome(word);

	cout << endl;
}

//���� ����(��������)
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

//���� ���� ���
void question_5()
{
	int arr[7];

	cout << "������ �Է��Ͻÿ�(�������� ����)" << endl;
	for (int i = 0; i < 7; i++)
		cin >> arr[i];

	DesSort(arr, 7);

	cout << "�迭 ��� : ";

	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	cout << endl << endl;
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
		}

	}

	return 0;
}