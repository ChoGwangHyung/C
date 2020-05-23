////const 선언
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
////ShowAllData에 매개변수 arr을 대상으로 const 선언을 한 이유 설명
//void question_1()
//{
//	cout << "ShowAllData함수의 매개변수 arr을 대상으로 const선언을 한 이유는 들어오는 데이터의 값이 변동되는 것을 막기 위해서이다" << endl << endl;
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
////ShowData의 잘못된 점 설명
//void question_2()
//{	
//	cout << "ShowData 함수에서 int*rptr = ptr; 이 부분이 잘못되었다. 그 이유는 포인터 rptr이 const형식의 ptr을 가리키고있는데 rptr을 이용해서 ptr의 값을 변경할 수 있다. 하지만 ptr은 const형식으로 값을 변경할 수 없기 때문에 잘못되었다." << endl << endl;
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
//		cout << "몇 번 문제를 보시겠습니까?(0을 입력하면 종료)" << endl;
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