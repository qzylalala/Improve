#include<iostream>

using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int total_time, total_num;
	int time[101], value[101];
	int dp[101][1001];
	while (cin >> total_time >> total_num && total_num != 0 && total_time != 0)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= total_num; i++)
			cin >> time[i] >> value[i];
		for(int i = 1; i <= total_num; i++)
			for (int j = 1; j <= total_time; j++)
			{
				if (time[i] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + value[i]);
			}
		cout << dp[total_num][total_time] << endl;
	}

	return 0;
}