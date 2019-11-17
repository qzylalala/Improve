#include<bits/stdc++.h>

#define max_num 1001
using namespace std;

struct student{
	string ID;
	string name;
	string sex;
	int age;
}info[max_num];


int main()
{
	int n, m;
	string ID;
	map<string, int> list;
	while(scanf("%d", &n) != EOF)
	{
	for(int i = 1; i <= n; i++)
	{
		cin >> info[i].ID >> info[i].name >> info[i].sex >> info[i].age;
		list[info[i].ID] = i;
	}
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> ID;
		map<string ,int>::iterator iter;
		iter = list.find(ID);
		if(iter != list.end())
		{
			int k = iter->second;
			cout << info[k].ID << " " << info[k].name << " " << info[k].sex << " " << info[k].age << endl;
		}
		else{
			cout << "No Answer!" << endl;
		}
	}
	}
	return 0; 
}
