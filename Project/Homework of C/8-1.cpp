////���ǹ� ����
//#include <iostream>
//
//using namespace std;
//
////100������ 7�� 9�� ��� ���(�ּҰ���� �ߺ� ��� �Ұ�)
//void question_1()
//{
//	for (int i = 1; i < 100; i++)
//	{
//		if (i % 7 == 0) cout << i << " ";
//		else if (i % 9 == 0) cout << i << " ";
//	}
//
//	cout << endl << endl;
//
//	return;
//}
//
////�� ���� ������ �Է¹޾� �� ���� ���� ���
//void question_2()
//{
//	int num1;
//	int num2;
//
//	int result;
//
//	cout << "�� ���� ������ �Է��Ͻÿ�(�� ���� ��)" << endl;
//	cin >> num1;
//	cin >> num2;
//
//	if (num1 > num2) result = num1 - num2;
//	else result = num2 - num1;
//
//	cout << "�� ���� ���� : " << result << endl << endl;
//
//	return;
//}
//
////����, ���� , ���� ������ �Է¹޾� 3������ ����� ���� ������ �´� ���� ���
//void question_3()
//{
//	int subject_score[3];
//	int sum = 0;
//	float result;
//
//	cout << "����, ����, ������ ������ ������� �Է��Ͻÿ�" << endl;
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> subject_score[i];
//		sum += subject_score[i];
//	}
//
//	result = sum / 3;
//
//	if (result >= 90) cout << "���� A�Դϴ�." << endl << endl;
//	else if (result >= 80) cout << "���� B�Դϴ�." << endl << endl;
//	else if (result >= 70) cout << "���� C�Դϴ�." << endl << endl;
//	else if (result >= 50) cout << "���� D�Դϴ�." << endl << endl;
//	else cout << "���� F�Դϴ�." << endl << endl;
//
//	return;
//}
//
////�� ���� ������ �Է¹޾� �� ���� ���� ���(���׿����ڸ� ���)
//void question_4()
//{
//	int num1;
//	int num2;
//
//	int result;
//
//	cout << "�� ���� ������ �Է��Ͻÿ�(�� ���� ��)" << endl;
//	cin >> num1;
//	cin >> num2;
//
//	result = num1 > num2? num1 - num2 : num2 - num1;
//
//	cout << "�� ���� ���� : " << result << endl << endl;
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
//
//		case 3:
//			question_3();
//			break;
//
//		case 4:
//			question_4();
//			break;
//		}
//
//	}
//
//	return 0;
//}