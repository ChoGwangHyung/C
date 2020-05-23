////조건문과 반복문 연습
//#include <iostream>
//
//using namespace std;
//
////9이하의 수 중에 2의 배수인 수들의 단의 수만큼만 구구단 출력
//void question_1()
//{
//	for (int i = 1; i < 9; i++)
//	{
//		if (i % 2 != 0) continue;
//
//		for (int j = 1; j < 10; j++)
//		{
//			cout << i << "X" << j << " = " << i * j << " ";
//
//			if (j == i) 
//			{
//				cout << endl;
//				break;
//			}
//		}		
//	}
//
//	cout << endl << endl;
//
//	return;
//}
//
//// i j + j i = 99 인 경우의 수 모두 출력
//void question_2()
//{
//	int result;
//	
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			result = (i * 10 + j) + (j * 10 + i);
//			if (result == 99) cout << i << j << "+" << j << i << " = 99  ";
//		}
//	}
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