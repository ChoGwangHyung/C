////미리 컴파일된 헤더 사용안함, sdl검사 끄기
//#include <iostream>
//
//using namespace std;
//
////5개의 정수를 입력받아 합을 출력하는 프로그램
//void question_1()
//{
//	int arr[5];
//	int sum = 0;
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << i + 1 << "번째 정수 입력 : ";
//		cin >> arr[i];
//		sum += arr[i];
//	}
//
//	cout << "합계 : " << sum << endl << endl;
//
//	return;
//}
//
////이름과 전화번호를 문자열의 형태로 입력 받아 그대로 출력하는 프로그램
//void question_2()
//{
//	char name[10], phone_number[20];
//
//	cout << "이름 : ";
//	cin >> name;
//
//	cout << "폰 번호 : ";
//	cin >> phone_number;
//
//	cout << "이름은 " << name << "이고 폰 번호는 " << phone_number << "이다." << endl << endl;
//
//	return;
//}
//
////숫자를 하나 입력 받아 그 숫자에 해당하는 구구단을 출력하는 프로그램
//void question_3()
//{
//	int num;
//
//	cout << "구구단 : ";
//	cin >> num;
//
//	for (int i = 1; i <= 9; i++)
//		cout << num << "X" << i << " = " << num * i << endl;
//
//	cout << endl;
//
//	return;
//}
//
////판매원들의 급여 계산 프로그램
//void question_4()
//{
//	int pay = 50;
//	int sales = 0;
//
//	while (sales != -1)
//	{
//		cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
//		cin >> sales;
//
//		if (sales == -1)
//		{
//			cout << "프로그램을 종료합니다." << endl << endl;
//			return;
//		}
//		else
//		{
//			pay += (sales / 100 * 12);
//			cout << "이번 달 급여 : " << pay << endl;
//		}
//	}
//
//	return;
//}
//
//int main()
//{
//	int menu_select = 0;
//
//	while (menu_select != -1)
//	{
//		cout << "어떤 문제를 보시겠습니까?(1~4, -1 입력시 종료) : ";
//		cin >> menu_select;
//
//		switch (menu_select)
//		{
//		case -1:
//			cout << "종료" << endl;
//			return 0;
//		case 1:
//			question_1();
//			break;
//		case 2:
//			question_2();
//			break;
//		case 3:
//			question_3();
//			break;
//		case 4:
//			question_4();
//			break;
//		default:
//			cout << "다시 입력하시오" << endl << endl;
//			break;
//		}
//	}
//
//	return 0;
//}