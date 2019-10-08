/* https://blog.csdn.net/chen_yuazzy/article/details/76285322 */
#include<iostream>
#include<cstring>
using namespace  std;
char Map[15][15];
int vis[15][15];
int a, b; //a表示行，b表示列 
int ans1, ans2;
void DFS(int row, int col) {
	if (row<1 || col<1 || row>a || col>b)
	{
		cout << ans1 << " step(s) to exit" << endl;
		return;
	}
	if (vis[row][col] == 1)  ans2++;

	if (vis[row][col] == 2)
	{
		cout << ans1 - 2 * ans2 << " step(s) before a loop of " << ans2 << " step(s)" << endl;
		return;
	}

	ans1++;
	vis[row][col]++;
	if (Map[row][col] == 'N') DFS(row - 1, col);
	if (Map[row][col] == 'S') DFS(row + 1, col);
	if (Map[row][col] == 'W') DFS(row, col - 1);
	if (Map[row][col] == 'E') DFS(row, col + 1);
}//ans1 记录每一步， ans2 记录循环的步数

int main() {
	int start;
	while (cin >> a >> b >> start && a&&b&&start)
	{
		ans1 = 0, ans2 = 0;
		memset(vis, 0, sizeof(vis));
		memset(Map, '0', sizeof(Map));//随意初始化一个值 
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				cin >> Map[i][j];
		DFS(1, start);
	}
	return 0;
}