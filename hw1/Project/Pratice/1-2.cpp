//2020-03-30 
//Create check palindrome project
//use stack of C++

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void IsPalindrome(string text)
{
	stack<char> st;

	for (int i = 0; i < text.size(); i++)		//push text in stack
		st.push(text[i]);

	bool yes = true;

	for (int i = 0; i < text.size() / 2; i++)		//0 to size of the stack
	{
		if (text[i] != st.top())				//check palindrome
		{
			yes = false;
			break;
		}
		st.pop();
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

	IsPalindrome(text1);			//check palindrome	

	cin >> text2;

	IsPalindrome(text2);			//check palindrome

	return 0;
}