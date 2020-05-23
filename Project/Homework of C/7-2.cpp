////while을 이용한 이중 반복문 연습
//#include <iostream>
//
//using namespace std;
//
////1이상의 정수 5개를 입력받아 그 정수들의 합 출력
//void question_1()
//{
//	int num = 5;
//	int sum = 0;
//
//	while (num > 0)
//	{
//		int input;
//
//		cout << "1 이상의 정수 5개를 입력하시오(정수의 합)" << endl;
//		cin >> input;
//
//		while (input < 1)
//		{
//			cout << "1이상의 정수가 아닙니다. 다시 입력하십시오" << endl;
//			cin >> input;
//		}
//
//		sum += input;
//		num--;
//	}
//
//	cout << "입력된 정수의 총합은 : " << sum << endl << endl;
//
//	return;
//}
//
////별 찍기
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