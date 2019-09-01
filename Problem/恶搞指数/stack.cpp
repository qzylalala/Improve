#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
	char temp;
	string str;
	while (getline(cin, str))
	{
		int count_all = 0;
		stack<char> check;
		for (int i = 0; str[i] != '\0'; i++)
		{
			temp = str[i];
			if (temp == '(')
				check.push(temp);
			else if (temp == ')') {
				if (check.top() == '(')
					check.pop();
			}
			else
				break;
		}
		count_all = check.size();
		cout << count_all << endl;
		count_all = 0;
	}

	return 0;
}