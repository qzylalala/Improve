#include <iostream>
#include <algorithm>
#include <cstring>//memset函数需要这个头文件
#define MAX 25
using namespace std;

int f[MAX][30001];

int main()
{
	int n, m, value[MAX], weight[MAX];
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= m; i++)
	{
		value[i] = value[i] * weight[i];
	}

	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (weight[i] > j)
				f[i][j] = f[i - 1][j];
			else
			{
				f[i][j] = max(f[i - 1][j - weight[i]] + value[i], f[i - 1][j]);
			}
		}
	}

	cout << f[m][n];
	return 0;
}

