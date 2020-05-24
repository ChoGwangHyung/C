//������� ���� ���α׷�
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
		cout << "����ID : " << this->account_num << endl;
		cout << "�� �� : " << this->name << endl;
		cout << "�� �� : " << this->cash << endl;
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

	cout << "[���°���]" << endl;
	cout << "����ID : ";
	cin >> id;
	if (FindAccount(list, size, id) != -1)
	{
		cout << "�̹� �ִ� ����ID �Դϴ�." << endl;
		return;
	}
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> cash;

	list[size++].OpenAccount(id, name, cash);
}

bool IsCorrectAccount(int num)
{
	if (num == -1)
	{
		cout << "���� ����ID�Դϴ�." << endl;
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

	cout << "[��    ��]" << endl;
	cout << "����ID : ";
	cin >> id;

	index = FindAccount(list, size, id);
	if (IsCorrectAccount(index) == false)
		return;

	cout << "�Աݾ� : ";
	cin >> cash;

	list[index].Deposit(cash);
	cout << "�ԱݿϷ�" << endl;
}

void Withdrawal(Account list[], int size)
{
	int id;
	int cash;
	int index;

	cout << "[��    ��]" << endl;
	cout << "����ID : ";
	cin >> id;

	index = FindAccount(list, size, id);
	if (IsCorrectAccount(index) == false)
		return;

	cout << "��ݾ� : ";
	cin >> cash;

	list[index].Withdrawal(cash);
	cout << "��ݿϷ�" << endl;
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
		cout << "1. ���°���" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "���� : ";
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
			cout << "���α׷� ����" << endl;
			return 0;
			break;
		default:
			cout << "�޴� ��ȣ�� �ٽ� �Է¹ٶ�" << endl;
			break;
		}
		cout << endl;
	}
}