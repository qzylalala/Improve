/* https://blog.csdn.net/chen_yuazzy/article/details/76304068 */
#include<iostream>
#include<cstring>
using namespace std;
char Map[5][5];
bool vis[5][5];
int n, ans;

bool check(int x, int y)
{
	if (x<1 || y<1 || x>n || y>n) return false;
	else return true;
}

bool Recheck(int x, int y)
{
	if (Map[x][y] == 'X') return false;
	//向右、左搜索 
	for (int i = x; check(i, y); ++i)
	{
		if (Map[i][y] == 'X') break;              //若是墙 
		else if (vis[i][y] == true) return false;  //若遇到了炮弹，不能填，返回false 
	}
	for (int i = x; check(i, y); --i)
	{
		if (Map[i][y] == 'X') break;
		else if (vis[i][y] == true) return false;
	}
	//向下、上搜索 
	for (int i = y; check(x, i); ++i)
	{
		if (Map[x][i] == 'X') break;
		else if (vis[x][i] == true) return false;
	}
	for (int i = y; check(x, i); --i)
	{
		if (Map[x][i] == 'X') break;
		else if (vis[x][i] == true) return false;
	}
	//若四周方向中，存在墙挡住炮弹或者四周都空旷，则可以填入炮弹，返回true 
	return true;
}


void DFS(int num)
{
	if (num > ans) ans = num;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (Recheck(i, j))    //检查函数的重要！！！！ 
			{
				vis[i][j] = true;//填入炮弹 
				DFS(num + 1);
				vis[i][j] = false;//回溯 
			}
}
int main() {
	while (cin >> n && n)
	{
		memset(vis, false, sizeof(vis));
		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> Map[i][j];
		DFS(0);
		cout << ans << endl;
	}
	return 0;
}