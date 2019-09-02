/*走迷宫问题，题目要求链接https://blog.csdn.net/UnKfrozen/article/details/85040841*/
#include<stdio.h>
#include<iostream>

using namespace std;

int n, m, p, q, min = 999999;
char a[51][51];
int visit[51][51];

int DFS(int x, int y, int step)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int tx, ty, k;
	if (x == p && y == q)
	{
		if (step < min) min = step;
		return min;
	}
	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx<1 || tx>n || ty<1 || ty>m) continue;
		if (a[tx][ty] == '.' && visit[tx][ty] == 0)
		{
			visit[tx][ty] = 1;
			DFS(tx, ty, step + 1);
			visit[tx][ty] = 0;
		}
	}
	return;
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	p = n, q = m;
	visit[1][1] = 1;
	DFS(1, 1, 1);

	cout << min;
	return 0;
}