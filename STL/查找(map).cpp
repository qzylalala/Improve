#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	map<int, int> CountMap;
	for(int i = 1; i <= 100; i++)
	{
		int temp;
		scanf("%d", &temp);
		
		CountMap[temp]++;
	}
	scanf("%d", &x);
	map<int, int>::iterator iter;
	iter = CountMap.find(x);
	cout << x << "������a�г��ֵĴ���Ϊ" << iter->second<< endl;
	 
	return 0;
}
