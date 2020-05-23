////조건문 연습
//#include <iostream>
//
//using namespace std;
//
////100이하의 7과 9의 배수 출력(최소공배수 중복 출력 불가)
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
////두 개의 정수를 입력받아 두 수의 차를 출력
//void question_2()
//{
//	int num1;
//	int num2;
//
//	int result;
//
//	cout << "두 개의 정수를 입력하시오(두 수의 차)" << endl;
//	cin >> num1;
//	cin >> num2;
//
//	if (num1 > num2) result = num1 - num2;
//	else result = num2 - num1;
//
//	cout << "두 수의 차는 : " << result << endl << endl;
//
//	return;
//}
//
////국어, 영어 , 수학 점수를 입력받아 3과목의 평균을 내서 점수에 맞는 학점 출력
//void question_3()
//{
//	int subject_score[3];
//	int sum = 0;
//	float result;
//
//	cout << "국어, 영어, 수학의 점수를 순서대로 입력하시오" << endl;
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> subject_score[i];
//		sum += subject_score[i];
//	}
//
//	result = sum / 3;
//
//	if (result >= 90) cout << "학점 A입니다." << endl << endl;
//	else if (result >= 80) cout << "학점 B입니다." << endl << endl;
//	else if (result >= 70) cout << "학점 C입니다." << endl << endl;
//	else if (result >= 50) cout << "학점 D입니다." << endl << endl;
//	else cout << "학점 F입니다." << endl << endl;
//
//	return;
//}
//
////두 개의 정수를 입력받아 두 수의 차를 출력(삼항연산자를 사용)
//void question_4()
//{
//	int num1;
//	int num2;
//
//	int result;
//
//	cout << "두 개의 정수를 입력하시오(두 수의 차)" << endl;
//	cin >> num1;
//	cin >> num2;
//
//	result = num1 > num2? num1 - num2 : num2 - num1;
//
//	cout << "두 수의 차는 : " << result << endl << endl;
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