#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int money, num;
	int cost[101], value[101];
	int dp[101][1001];
	while (cin >> money >> num)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= num; i++)
		{
			cin >> cost[i] >> value[i];
		}

		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= money; j++)
			{
				if (dp[i][j] > cost[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + value[i]);
			}
		}

		cout << dp[num][money] << endl;
	}

	return 0;
}