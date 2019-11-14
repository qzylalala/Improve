#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	while(n--)
	{
		stack<char> s;
		string str;
		cin >> str;
		int len = str.length();
		
		for(int i = 0; i < len; i++)
		{
			if(str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else if(str[i] == ')')
			{
				if(s.top() == '(')
				{
					s.pop();
				}
				else
				{
					s.push(str[i]);
				} 
			}
			else
			{
				if(s.top() == '[')
				{
					s.pop();
				}
				else
					s.push(str[i]);
			}
		}
		if(s.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
} 
