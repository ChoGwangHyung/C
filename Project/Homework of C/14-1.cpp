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
////변수 num에 저장된 값의 제곱을 계산하는 함수를 정의 호출
//void question_1()
//{
//	int num;
//
//	cout << "정수를 입력하시오(제곱) : ";
//	cin >> num;
//
//	cout << "num의 제곱은(call-by-vaule) : " << SquareByValue(num) << endl;
//	SquareByReference(num);
//	cout << "num의 제곱은(call-by-reference) : " << num << endl << endl;
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
//// 3개의 정수를 스왑
//void question_2()
//{
//	int num1, num2, num3;
//
//	cout << "정수를 입력하시오(스왑)" << endl;
//	cin >> num1 >> num2 >> num3;
//
//	cout << "스왑 전" << endl;
//	printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);
//
//	Swap3(&num1, &num2, &num3);
//
//	cout << "스왑 후" << endl;
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