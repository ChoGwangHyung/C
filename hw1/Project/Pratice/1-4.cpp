//2020-03-30 
//Create check palindrome project
//use deque of C++

#include <iostream>
#include <deque>
#include <string>

using namespace std;

void IsPalindrome(string text)
{
	deque<char> dq;

	for (int i = 0; i < text.size(); i++)		//push text in circle queue
		dq.push_back(text[i]);

	bool yes = true;

	for (int i = 0; i < text.size() / 2; i++)		//0 to size of the circle queue / 2
	{
		if (dq.back() != dq.front())						//check palindrome
		{
			yes = false;
			break;
		}
		dq.pop_back();
		dq.pop_front();		
	}

	if (yes)
		cout << "회문입니다." << endl;
	else
		cout << "회문이 아닙니다." << endl;
}

int main()
{
	string text1;
	string text2;

	cin >> text1;

	IsPalindrome(text1);					//check palindrome

	cin >> text2;

	IsPalindrome(text2);					//check palindrome

	return 0;
}
