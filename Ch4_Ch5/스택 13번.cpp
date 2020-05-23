#include <iostream>

using namespace std;

const int MAXSIZE = 6;

typedef struct Stack {

	int last;
	int data[MAXSIZE];

}stack;


bool IsEmpty(stack& test)
{
	if (test.last == -1)return true;
	else return false;
}

bool IsFull(stack& test)
{
	if (test.last == MAXSIZE - 1)return true;
	else return false;
}

void Initialize(stack& test)
{
	test.last = -1;
}

int Pop(stack& test)
{
	if (IsEmpty(test)) {
		cout << "Is Empty" << endl;
		exit(1);
	}
	else return test.data[test.last--];

}

int Push(stack& test, int x)
{
	if (IsFull(test)) {
		cout << "Is Full" << endl;
		exit(1);
	}

	test.data[++test.last] = x;

	return test.data[test.last];
}

int Top(stack& test)
{
	if (IsEmpty(test)) {
		cout << "Is Empty" << endl;
		exit(1);
	}

	else return test.data[test.last];
}

int Size(stack& test)
{
	return test.last + 1;
}

void RemoveRepetNum(stack& test, stack& temp)
{
	if (test.last == -1)return;

	if (test.data[test.last] != test.data[test.last - 1]) {
		Push(temp, test.data[test.last]);
		test.last--;
		RemoveRepetNum(test, temp);
	}
	else {
		Pop(test);
		RemoveRepetNum(test, temp);
	}
}


int main()
{
	stack test;
	stack print;

	Initialize(test);
	Initialize(print);	
		
	cout << "정수를 입력하시오 : ";
	cout << Push(test, 1) << " ";
	cout << Push(test, 2) << " ";
	cout << Push(test, 2) << " ";
	cout << Push(test, 2) << " ";
	cout << Push(test, 3) << " ";
	cout << Push(test, 3) << " " << endl;

	RemoveRepetNum(test, print);

	cout << "출력 : ";
	cout << Pop(print) << " ";
	cout << Pop(print) << " ";
	cout << Pop(print) << " ";

	return 0;
}