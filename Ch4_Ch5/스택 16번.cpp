//#include <iostream>
//
//using namespace std;
//
//const int MAXSIZE = 20;
//
//typedef struct Stack {
//
//	int last;
//	char data[MAXSIZE];
//
//}stack;
//
//
//bool IsEmpty(stack& test)
//{
//	if (test.last == -1)return true;
//	else return false;
//}
//
//bool IsFull(stack& test)
//{
//	if (test.last == MAXSIZE - 1)return true;
//	else return false;
//}
//
//void Initialize(stack& test)
//{
//	test.last = -1;
//}
//
//char Pop(stack& test)
//{
//	if (IsEmpty(test)) {
//		cout << "Is Empty" << endl;
//		exit(1);
//	}
//	else return test.data[test.last--];
//
//}
//
//char Push(stack& test, char x)
//{
//	if (IsFull(test)) {
//		cout << "Is Full" << endl;
//		exit(1);
//	}
//
//	test.data[++test.last] = x;
//
//	return test.data[test.last];
//}
//
//char Top(stack& test)
//{
//	if (IsEmpty(test)) {
//		cout << "Is Empty" << endl;
//		exit(1);
//	}
//
//	else return test.data[test.last];
//}
//
//char Size(stack& test)
//{
//	return test.last + 1;
//}
//
//void IsPalindrome(stack& test)
//{
//	stack temp;
//	Initialize(temp);
//
//	bool yes = true;
//
//	for (int i = 0; i < Size(test); i++)
//	{
//		if (test.data[i] >= 65 && test.data[i] <= 90)
//			Push(temp, test.data[i] + 32);
//		else
//			Push(temp, test.data[i]);
//	}
//
//	for (int i = 0; i < Size(test); i++)
//	{
//		char data = Pop(temp);
//
//		if (data != test.data[i] &&
//			(data >= 92 && data <= 122))
//		{
//			yes = false;
//			break;
//		}
//	}
//	if (yes)
//		cout << "회문입니다." << endl;
//	else
//		cout << "회문이 아닙니다." << endl;
//}
//
//
//int main()
//{
//	stack test;
//
//	Initialize(test);
//
//	cout << "문자열을 입력하시오 : ";
//	cout << Push(test, 'm');
//	cout << Push(test, 'a');
//	cout << Push(test, 'd');
//	cout << Push(test, 'a');
//	cout << Push(test, 'm');
//	cout << Push(test, ',') << " ";
//	cout << Push(test, 'i');
//	cout << Push(test, '\'');
//	cout << Push(test, 'm') << " ";
//	cout << Push(test, 'a');
//	cout << Push(test, 'd');
//	cout << Push(test, 'a');
//	cout << Push(test, 'm') << endl;
//
//	IsPalindrome(test);
//
//	Initialize(test);
//
//	cout << "문자열을 입력하시오 : ";
//	cout << Push(test, 'm');
//	cout << Push(test, 'a');
//	cout << Push(test, 'd') ;
//	cout << Push(test, 'm') << endl;
//
//	IsPalindrome(test);
//
//	return 0;
//}