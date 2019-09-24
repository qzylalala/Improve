#include <iostream>
#include <cstdio>
#define MAX_NUM 105
using namespace std;

int main()
{
	int high[MAX_NUM], left[MAX_NUM], right[MAX_NUM], n;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
			cin >> high[i];
		for (int i = 0; i < n; i++)
		{
			left[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (high[j] < high[i] && left[j] > left[i] - 1)   // 找出左边最长递增子序列
					left[i] = left[j] + 1;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			right[i] = 1;
			for (int j = n - 1; j > i; j--)
			{
				if (high[j] < high[i] && right[j] > right[i] - 1)  // 找出右边最长递减子序列
					right[i] = right[j] + 1;
			}
		}
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (max < left[i] + right[i] - 1)
				max = left[i] + right[i] - 1;  // 寻找最多合唱人数
		}
		cout << n - max << endl;
	}
	return 0;
}