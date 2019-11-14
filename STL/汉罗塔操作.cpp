#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, p, q, a, b;
	cin >> n;
	
	while(n--)
	{
		int flag = 1;
		stack<int> s[4];
		cin >> p >> q;
		for(int i = 1; i <= p; i++)
		{
			s[1].push(p - i + 1);
		}
		while(q--)
		{
			cin >> a >> b;
			if(s[a].empty())
			{
				cout << "illegal" << endl;
				flag = 0;
				break;
			}
			else if(s[b].empty())
			{
				int t = s[a].top();
				s[b].push(t);
				s[a].pop();
			}
			else
			{
				if(s[a].top() > s[b].top())
				{
					cout << "illegal" << endl;
					flag = 0;
					break;
				}
				else
				{
					int t = s[a].top();
					s[b].push(t);
					s[a].pop();
				}
			}
		}
		if(flag == 1)
			cout << "legal" << endl;
	}
	
	return 0;	
} 
