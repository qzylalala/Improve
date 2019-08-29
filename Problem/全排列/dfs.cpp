#include<iostream>
#include<stdlib.h>

int n;
int visit[11], num[11];

void dfs(int depth)
{
	if (depth > n)
	{
		std::cout << num[1];
		for (int i = 2; i <= n; i++)
			std::cout << " " << num[i];
		std::cout << "\n";
	}

	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				visit[i] = 1;
				num[depth] = i;
				dfs(depth + 1);
				visit[i] = 0;
			}
		}
	}
}


int main()
{
	std::cin >> n;
	dfs(1);

	return 0;
}