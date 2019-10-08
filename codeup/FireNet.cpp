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
	//���ҡ������� 
	for (int i = x; check(i, y); ++i)
	{
		if (Map[i][y] == 'X') break;              //����ǽ 
		else if (vis[i][y] == true) return false;  //���������ڵ������������false 
	}
	for (int i = x; check(i, y); --i)
	{
		if (Map[i][y] == 'X') break;
		else if (vis[i][y] == true) return false;
	}
	//���¡������� 
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
	//�����ܷ����У�����ǽ��ס�ڵ��������ܶ��տ�������������ڵ�������true 
	return true;
}


void DFS(int num)
{
	if (num > ans) ans = num;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (Recheck(i, j))    //��麯������Ҫ�������� 
			{
				vis[i][j] = true;//�����ڵ� 
				DFS(num + 1);
				vis[i][j] = false;//���� 
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