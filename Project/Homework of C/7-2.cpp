////while�� �̿��� ���� �ݺ��� ����
//#include <iostream>
//
//using namespace std;
//
////1�̻��� ���� 5���� �Է¹޾� �� �������� �� ���
//void question_1()
//{
//	int num = 5;
//	int sum = 0;
//
//	while (num > 0)
//	{
//		int input;
//
//		cout << "1 �̻��� ���� 5���� �Է��Ͻÿ�(������ ��)" << endl;
//		cin >> input;
//
//		while (input < 1)
//		{
//			cout << "1�̻��� ������ �ƴմϴ�. �ٽ� �Է��Ͻʽÿ�" << endl;
//			cin >> input;
//		}
//
//		sum += input;
//		num--;
//	}
//
//	cout << "�Էµ� ������ ������ : " << sum << endl << endl;
//
//	return;
//}
//
////�� ���
//void question_2()
//{
//	int i = 0;	
//
//	while (i < 5)
//	{
//		int j = 0;
//
//		while (j < i)
//		{
//			cout << "0";
//			j++;
//		}
//		cout << "*" << endl;
//
//		i++;
//	}
//
//	cout << endl;
//
//	return;
//}
//
//int main()
//{
//	int what_question;
//
//	while (true)
//	{
//		cout << "�� �� ������ ���ðڽ��ϱ�?(0�� �Է��ϸ� ����)" << endl;
//		cin >> what_question;
//
//		cout << endl;
//
//		switch (what_question)
//		{
//		case 0:
//			return 0;
//
//		case 1:
//			question_1();
//			break;
//
//		case 2:
//			question_2();
//			break;
//		}
//
//	}
//
//	return 0;
//}