////call-by-value and call-by-reference
//#include <iostream>
//
//using namespace std;
//
////call-by-value
//int SquareByValue(int num)
//{
//	return num * num;
//}
//
////call-by-reference
//void SquareByReference(int& num)
//{
//	num = num * num;
//
//	return;
//}
//
////���� num�� ����� ���� ������ ����ϴ� �Լ��� ���� ȣ��
//void question_1()
//{
//	int num;
//
//	cout << "������ �Է��Ͻÿ�(����) : ";
//	cin >> num;
//
//	cout << "num�� ������(call-by-vaule) : " << SquareByValue(num) << endl;
//	SquareByReference(num);
//	cout << "num�� ������(call-by-reference) : " << num << endl << endl;
//
//	return;
//}
//
//void Swap3(int* num1, int* num2, int* num3)
//{
//	int temp = *num3;
//	*num3 = *num2;
//	*num2 = *num1;	
//	*num1 = temp;
//
//	return;
//}
//
//// 3���� ������ ����
//void question_2()
//{
//	int num1, num2, num3;
//
//	cout << "������ �Է��Ͻÿ�(����)" << endl;
//	cin >> num1 >> num2 >> num3;
//
//	cout << "���� ��" << endl;
//	printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);
//
//	Swap3(&num1, &num2, &num3);
//
//	cout << "���� ��" << endl;
//	printf("num1 = %d, num2 = %d, num3 = %d\n\n", num1, num2, num3);
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