#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string str;
	cin >> n;
	
	while(n--)
	{
		cin >> str;
		sort(str.begin(), str.end());
		
		for(int i = 0; i < str.size() - 1; i++)
		{
			cout << str[i] << " ";
		}
		cout << str[str.size() - 1] << endl;
	}
	
	return 0;
}
