#include<iostream>
#include<stdlib.h>

using namespace std;

int n, count_all = 0;
int num[11] = { 0 };

bool check(int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		if (col == num[i] || abs(row - i) == abs(col - num[i]))//不同列，不在一条斜线上
			return false;
	}
	return true;
}

void dfs(int depth)
{
	if (depth > n)
	{
		cout << num[1];
		for (int i = 2; i <= n; i++)
			cout << " " << num[i];
		cout << endl;
		count_all++;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (check(depth, i))
			{
				num[depth] = i;
				dfs(depth + 1);
				num[depth] = 0;//还原,这一步是必须的。因为在上面赋值之前有一次check用到了num[i]的值，因此必须还原。
			}
		}
	}
}


int main()
{
	cin >> n;
	dfs(1);
	if (count_all == 0)
		cout << "no solute!" << endl;;

	system("pause");
	return 0;
}