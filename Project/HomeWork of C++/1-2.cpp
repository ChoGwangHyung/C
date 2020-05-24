////미리 컴파일된 헤더 사용안함, sdl검사 끄기
//#include <iostream>
//
//using namespace std;
//
////함수 오버로딩
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//
//	return;
//}
//
//void swap(char* a, char* b)
//{
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//
//	return;
//}
//
//void swap(double* a, double* b)
//{
//	double temp = *a;
//	*a = *b;
//	*b = temp;
//
//	return;
//}
//
//int main()
//{
//	int num1 = 20, num2 = 30;
//	swap(&num1, &num2);
//	cout << num1 << ' ' << num2 << endl;
//
//	char ch1 = 'A', ch2 = 'Z';
//	swap(&ch1, &ch2);
//	cout << ch1 << ' ' << ch2 << endl;
//
//	double dbl1 = 1.111, dbl2 = 5.555;
//	swap(&dbl1, &dbl2);
//	cout << dbl1 << ' ' << dbl2 << endl;
//
//	return 0;
//}