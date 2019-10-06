#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct node
{
	int x, y, step;
};
//结点

int vis[8][8];   //存放访问点 
int sx, sy, ex, ey, ans;   //起点 末点 
int to[8][2] = { -1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2 };   //马可能的坐标移动 8种可能

int check(int x, int y)
{
	if (x < 0 || y < 0 || x >= 8 || y >= 8)
		return 1;
	if (vis[x][y])
		return 1;
	return 0;
}
// 检测是否到末尾 结点是否被访问。
void bfs()
{
	int i;
	queue<node> Q;    //广度搜索的队列 先进先出。
	node a, next;
	a.x = sx;
	a.y = sy;
	a.step = 0;
	vis[sx][sy] = 1;
	Q.push(a);
	while (!Q.empty())
	{
		a = Q.front();
		Q.pop();
		if (a.x == ex && a.y == ey)
		{
			ans = a.step;
			return;
		}     //如果起点 末点相同 step=0
		for (i = 0; i < 8; i++)
		{
			next = a;
			next.x += to[i][0];
			next.y += to[i][1];//访问相邻八个结点
			if (check(next.x, next.y))
				continue;        //出现墙 被访问 继续
			next.step = a.step + 1;     //找出8步后  步数加1
				vis[next.x][next.y] = 1;   //标记访问过的点。
			Q.push(next);
		}
	}
	return;
}

int main()
{
	char ch1[10], ch2[10];
	while (~scanf("%s%s", ch1, ch2))
	{
		sx = ch1[0] - 'a';
		sy = ch1[1] - '1';
		ex = ch2[0] - 'a';
		ey = ch2[1] - '1';
		memset(vis, 0, sizeof(vis));
		bfs();
		printf("To get from %s to %s takes %d knight moves.\n", ch1, ch2, ans);
	}

	return 0;
}