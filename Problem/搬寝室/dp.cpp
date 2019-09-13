#include<iostream>
#include<algorithm>
using namespace std;
#define INF 2147483646
int dp[2005][1005];
int main() {
	int n, k, val[2005];
	dp[0][0] = 0;
	while (scanf("%d%d", &n, &k) != EOF && n&&k) {
		val[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		sort(val + 1, val + n + 1);
		for (int i = 0; i <= n; i++)
			for (int j = 1; j <= k; j++)
				dp[i][j] = INF;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j * 2 <= i; j++)
				dp[i][j] = min(dp[i - 2][j - 1] + (val[i] - val[i - 1])*(val[i] - val[i - 1]), dp[i - 1][j]);
		printf("%d\n", dp[n][k]);
	}
	return 0;
}