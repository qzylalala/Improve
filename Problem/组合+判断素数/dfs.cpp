#include<iostream>
#include<stdlib.h>

using namespace std;


int n, k;
int countAll = 0, ans = 0;
int num[22] = { 0 }, visit[22] = { 0 }, p[22] = {0};

bool isPrime(int n)
{
	if (n == 2)
		return true;
	else
	{
		for (int i = 2; i * i <= n; i++)
			if (n%i == 0)
				return false;
		return true;
	}
}


void dfs(int depth)
{
	if (depth > k)
	{
		if (isPrime(ans))
			countAll++;
	}

	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && p[depth-1] < i)//保证全排列有序
			{
				p[depth] = i;
				ans += num[i];
				visit[i] = 1;
				dfs(depth + 1);
				visit[i] = 0;
				ans -= num[i];
			}
		}
	}
}



int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> num[i], p[i] = i;
	dfs(1);
	cout << countAll << endl;

	return 0;
}