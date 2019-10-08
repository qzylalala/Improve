/*https://blog.csdn.net/chen_yuazzy/article/details/73656668 */
/*
#include<iostream>
#include<cstring>

using namespace std;
int n;
char map1[35][35];
int vis[35][35];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };


void dfs(int a, int b) {
	if (a > n || b > n || a <= 0 || b <= 0 || map1[a][b] == '#' || vis[a][b] == 1) return;
	vis[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = a + dir[i][0];
		int ty = b + dir[i][1];
		dfs(tx, ty);
	}
}//将未被墙壁包围的 ‘.’ 全部标记为 1

int main() {
	int i, j, cnt, ans, zx, zy;
	while (cin >> n) {
		cnt = 0, ans = 0;
		for (i = 1; i <= n; i++)//输入地图
			for (j = 1; j <= n; j++)
				cin >> map1[i][j];

		memset(vis, 0, sizeof(vis));
		dfs(1, 1);
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (vis[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						zx = i + dir[k][0];
						zy = j + dir[k][1];
						if (vis[zx][zy] == 0) cnt++;
					}
				}
			}
		}
		ans = 9 * (cnt - 4);//计算面积
		cout << ans << endl;
	}
	return 0;
}
*/