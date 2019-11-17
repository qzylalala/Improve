#include<bits/stdc++.h>

using namespace std;

typedef struct{
	string ID;
	string start;
	string end;
}man;
man info[1001]; 

bool cmp1(man info1, man info2)
{
	if(info1.start <= info2.start)
		return true;
	else
		return false;
}

bool cmp2(man info1, man info2)
{
	if(info1.end >= info2.end)
		return true;
	else
		return false;
}



int main()
{
	int n, m;
	cin >> n;
	while(n--)
	{
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			cin >> info[i].ID >> info[i].start >> info[i].end;
		}
		sort(info, info + m, cmp1);
		cout << info[0].ID << " ";
		sort(info, info + m, cmp2);
		cout << info[0].ID << endl;	
	}
	
	return 0;
}
