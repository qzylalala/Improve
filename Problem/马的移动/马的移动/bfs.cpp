#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct node
{
	int x, y, step;
};
//���

int vis[8][8];   //��ŷ��ʵ� 
int sx, sy, ex, ey, ans;   //��� ĩ�� 
int to[8][2] = { -1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2 };   //����ܵ������ƶ� 8�ֿ���

int check(int x, int y)
{
	if (x < 0 || y < 0 || x >= 8 || y >= 8)
		return 1;
	if (vis[x][y])
		return 1;
	return 0;
}
// ����Ƿ�ĩβ ����Ƿ񱻷��ʡ�
void bfs()
{
	int i;
	queue<node> Q;    //��������Ķ��� �Ƚ��ȳ���
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
		}     //������ ĩ����ͬ step=0
		for (i = 0; i < 8; i++)
		{
			next = a;
			next.x += to[i][0];
			next.y += to[i][1];//�������ڰ˸����
			if (check(next.x, next.y))
				continue;        //����ǽ ������ ����
			next.step = a.step + 1;     //�ҳ�8����  ������1
				vis[next.x][next.y] = 1;   //��Ƿ��ʹ��ĵ㡣
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