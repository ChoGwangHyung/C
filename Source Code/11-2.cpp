//�迭����� ���ڿ� ǥ��
#include <iostream>

using namespace std;

//�ϳ��� ���ܾ �Է¹޾� ���ܾ��� ���̸� ����Ͽ� ���
void question_1()
{
	char arr[10];
	int size = 0;

	cout << "���ܾ �Է��Ͻÿ� :  ";
	cin >> arr;

	for (int i = 0; arr[i] != NULL; i++)
		size++;

	cout << "���ܾ ���� �迭�� ���̴� : " << size << endl << endl;

	return;
}

//���ܾ �Է¹޾� �������� ������
void question_2()
{
	char arr[10];
	char reverse[10] = { NULL, };
	int size = 0;

	cout << "���ܾ �Է��Ͻÿ� :  ";
	cin >> arr;

	for (int i = 0; arr[i] != NULL; i++)
		size++;

	for (int i = 0; i < size; i++)
		reverse[i] = arr[size - i - 1];

	cout << "�Է¹��� ���ܾ��� ������ : " << reverse << endl << endl;

	return;
}

//���ܾ �Է¹޾� �ƽ�Ű�ڵ� ���� ���� ū ���� ���
void question_3()
{
	char arr[10];
	char result;

	cout << "���ܾ �Է��Ͻÿ� :  ";
	cin >> arr;

	result = arr[0];

	for (int i = 1; arr[i] != NULL; i++)
		if (result < arr[i]) result = arr[i];

	cout << "�ƽ�Ű �ڵ� ���� ���� ū ���ڴ� : " << result << endl << endl;

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