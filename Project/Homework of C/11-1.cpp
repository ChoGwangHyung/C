////1차원 배열의 활용
//#include <iostream>
//
//using namespace std;
//
////배열과 사이즈를 매개변수로 받아 max값 반환
//int Max(int arr[], int size)
//{
//	int result = arr[0];
//	for (int i = 1; i < size; i++)
//		if (result < arr[i])result = arr[i];
//
//	return result;
//}
//
////배열과 사이즈를 매개변수로 받아 min값 반환
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
////배열에 5개의 정수를 입력받아 최댓값, 최솟값, 정수의 총합 출력
//void question_1()
//{
//	int arr[5];
//
//	cout << "5개의 정수를 입력하시오" << endl;
//
//	for (int i = 0; i < 5; i++)
//		cin >> arr[i];
//
//	cout << "최댓값 : " << Max(arr, 5) << endl;
//	cout << "최솟값 : " << Min(arr, 5) << endl;
//	cout << "총  합 : " << Sum(arr, 5) << endl << endl;
//
//	return;
//}
//
////char형 1차원 배열을 선언과 동시에 "Good time"이라 초기화하고 이를 출력하라(%c로 출력)
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