/*http://codeup.cn/problem.php?id=1130*/
#include <stdio.h>
#include <string.h>
#define maxn 500+1
int dp[55][55 * 510] = { 0 };
int p[maxn] = { 0 };

int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{

		memset(dp, 0, sizeof(dp));
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
			sum += p[i];
		}//先求总重量sum
		int N = n / 2 + (n % 2 == 0 ? 0 : 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = min(N, i); j >= 1; j--)
			{
				for (int k = sum / 2; k >= 0; k--)
				{

					if (k - p[i] >= 0)
					{
						if (j - 1 == 0)
							dp[j][k] = (k == p[i] ? p[i] : 0);
						else
							if (dp[j - 1][k - p[i]] != 0)
								dp[j][k] = dp[j - 1][k - p[i]] + p[i];
					}

				}

			}

		}
		int w;
		for (int i = sum / 2; i >= 0; i--)
		{
			if (dp[N][i] != 0)
			{
				w = dp[N][i];
				break;
			}
		}
		int qq;
		if (w > sum - w)
		{
			qq = sum - w;
		}
		else
		{
			qq = w;
			w = sum - w;


		}
		printf("%d %d\n", qq, w);


	}
	return 0;
}
