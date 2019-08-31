#include<iostream>
#include<stdlib.h>

using namespace std;

int n, count_all = 0;
int num[11] = { 0 };

bool check(int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		if (col == num[i] || abs(row - i) == abs(col - num[i]))//��ͬ�У�����һ��б����
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
				num[depth] = 0;//��ԭ,��һ���Ǳ���ġ���Ϊ�����渳ֵ֮ǰ��һ��check�õ���num[i]��ֵ����˱��뻹ԭ��
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