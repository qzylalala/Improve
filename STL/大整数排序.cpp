#include <bits/stdc++.h>

using namespace std;
string str[101];

bool cmp(string s1, string s2)
{
	if(s1.size() < s2.size())
		return true;
	else if(s1.size() > s2.size())
		return false;
	else{
		if(s1 <= s2)
			return true;
		else
			return false;
	}
}

int main()
{
	int n;
	string num;
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> num;
		str[i] = num;
	}
	sort(str + 1, str + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		cout << str[i] << endl;
	}
	
	return 0;
}
