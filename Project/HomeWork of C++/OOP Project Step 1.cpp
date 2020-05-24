//은행계좌 관리 프로그램
#include <iostream>
#include <string>

using namespace std;

struct Account {
	int account_num;
	string name;
	int cash;

	Account()
	{
		account_num = -1;
		name = "";
		cash = 0;
	}

	void OpenAccount(int id, string name, int cash)
	{
		this->name = name;
		this->cash = cash;
		this->account_num = id;
	}

	int GetAccountNum() { return account_num; }

	void Deposit(int cash)
	{
		this->cash += cash;
	}

	void Withdrawal(int cash)
	{
		this->cash -= cash;
	}

	void PrintInfo()
	{
		cout << "계좌ID : " << this->account_num << endl;
		cout << "이 름 : " << this->name << endl;
		cout << "잔 액 : " << this->cash << endl;
	}
};

int FindAccount(Account list[], int size, int id)
{
	int result = -1;

	for (int i = 0; i < size; i++)
	{
		if (list[i].GetAccountNum() == id)
		{
			result = i;
			break;
		}
	}

	return result;
}

void OpenAccount(Account list[], int& size)
{
	string name;
	int id, cash;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	if (FindAccount(list, size, id) != -1)
	{
		cout << "이미 있는 계좌ID 입니다." << endl;
		return;
	}
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> cash;

	list[size++].OpenAccount(id, name, cash);
}

bool IsCorrectAccount(int num)
{
	if (num == -1)
	{
		cout << "없는 계좌ID입니다." << endl;
		return false;
	}
	else
		return true;
}

void Deposit(Account list[], int size)
{
	int id;
	int cash;
	int index;

	cout << "[입    금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	index = FindAccount(list, size, id);
	if (IsCorrectAccount(index) == false)
		return;

	cout << "입금액 : ";
	cin >> cash;

	list[index].Deposit(cash);
	cout << "입금완료" << endl;
}

void Withdrawal(Account list[], int size)
{
	int id;
	int cash;
	int index;

	cout << "[출    금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	index = FindAccount(list, size, id);
	if (IsCorrectAccount(index) == false)
		return;

	cout << "출금액 : ";
	cin >> cash;

	list[index].Withdrawal(cash);
	cout << "출금완료" << endl;
}

void PrintAllAccountInfo(Account list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		list[i].PrintInfo();
		cout << endl;
	}
}

int main()
{
	Account list[10];
	int size = 0;

	int menu_key = 0;

	while (menu_key != 5)
	{
		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : ";
		cin >> menu_key;

		cout << endl;

		switch (menu_key)
		{
		case 1:
			OpenAccount(list, size);
			break;
		case 2:
			Deposit(list, size);
			break;
		case 3:
			Withdrawal(list, size);
			break;
		case 4:
			PrintAllAccountInfo(list, size);
			break;
		case 5:
			cout << "프로그램 종료" << endl;
			return 0;
			break;
		default:
			cout << "메뉴 번호를 다시 입력바람" << endl;
			break;
		}
		cout << endl;
	}
}