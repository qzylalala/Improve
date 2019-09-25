#include<iostream>
#include<stdlib.h>
#include<algorithm>

#define max 50000
using namespace std;

struct Info {
	int start;
	int end;
	int num;
	int flag = 0;
};

bool overlap(Info a, Info b)
{
	if (b.start >= a.end)
		return false;
	else
		return true;
}

bool cmp(Info a, Info b)
{
	return a.start < b.start;
}



int main()
{
	int n, m;
	Info info[max];
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			cin >> info[i].start >> info[i].end >> info[i].num;
		sort(info, info + n, cmp);

		int i = 1;
		while (info[i++].num > m)
			cout << "0" << endl;
		cout << "1" << endl;
		info[i - 1].flag = 1;

		for (int j = i; j <= n; j++)
		{
			int remain = m;
			for (int k = i - 1; k < j; k++)
			{
				if (info[k].flag == 0)
					continue;
				else
				{
					if (overlap(info[k], info[j]))
						remain -= info[k].num;
				}
			}

			if (info[j].num <= remain)
			{
				info[j].flag = 1;
				cout << "1" << endl;
			}
			else
				cout << "0" << endl;
		}
	}

	system("pause");
	return 0;
}