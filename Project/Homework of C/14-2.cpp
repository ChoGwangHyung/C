////const ����
//#include <iostream>
//
//using namespace std;
//
////void ShowAllData(const int* arr, int len)
////{
////	int i;
////	for (i = 0; i < len; i++)
////		printf("%d ", arr[i]);
////}
//
////ShowAllData�� �Ű����� arr�� ������� const ������ �� ���� ����
//void question_1()
//{
//	cout << "ShowAllData�Լ��� �Ű����� arr�� ������� const������ �� ������ ������ �������� ���� �����Ǵ� ���� ���� ���ؼ��̴�" << endl << endl;
//
//	return;
//}
//
////void ShowData(const int *ptr)
////{
////	int *rptr = ptr;
////	printf("%d \n", *rptr);
////	*rptr = 20;
////}
////
////int main(void)
////{
////	int num = 10;
////	int* ptr = &num;
////	ShowData(ptr);
////	return 0;
////}
//
////ShowData�� �߸��� �� ����
//void question_2()
//{	
//	cout << "ShowData �Լ����� int*rptr = ptr; �� �κ��� �߸��Ǿ���. �� ������ ������ rptr�� const������ ptr�� ����Ű���ִµ� rptr�� �̿��ؼ� ptr�� ���� ������ �� �ִ�. ������ ptr�� const�������� ���� ������ �� ���� ������ �߸��Ǿ���." << endl << endl;
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