#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str))
	{
		sort(str.begin(), str.end());
		cout << str << endl;
	}
	
	return 0;
}
