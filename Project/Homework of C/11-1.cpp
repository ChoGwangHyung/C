////1���� �迭�� Ȱ��
//#include <iostream>
//
//using namespace std;
//
////�迭�� ����� �Ű������� �޾� max�� ��ȯ
//int Max(int arr[], int size)
//{
//	int result = arr[0];
//	for (int i = 1; i < size; i++)
//		if (result < arr[i])result = arr[i];
//
//	return result;
//}
//
////�迭�� ����� �Ű������� �޾� min�� ��ȯ
//int Min(int arr[], int size)
//{
//	int result = arr[0];
//	for (int i = 1; i < size; i++)
//		if (result > arr[i])result = arr[i];
//
//	return result;
//}
//
//int Sum(int arr[], int size)
//{
//	int result = 0;
//	for (int i = 0; i < size; i++)
//		result += arr[i];
//
//	return result;
//}
//
////�迭�� 5���� ������ �Է¹޾� �ִ�, �ּڰ�, ������ ���� ���
//void question_1()
//{
//	int arr[5];
//
//	cout << "5���� ������ �Է��Ͻÿ�" << endl;
//
//	for (int i = 0; i < 5; i++)
//		cin >> arr[i];
//
//	cout << "�ִ� : " << Max(arr, 5) << endl;
//	cout << "�ּڰ� : " << Min(arr, 5) << endl;
//	cout << "��  �� : " << Sum(arr, 5) << endl << endl;
//
//	return;
//}
//
////char�� 1���� �迭�� ����� ���ÿ� "Good time"�̶� �ʱ�ȭ�ϰ� �̸� ����϶�(%c�� ���)
//void question_2()
//{
//	char arr[] = "Good time";
//
//	for (int i = 0; i < 10; i++)
//		printf("%c", arr[i]);
//
//	cout << endl << endl;
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