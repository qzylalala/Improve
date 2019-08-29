/*http://codeup.cn/contest.php?cid=100000608 */

#include<iostream>
#include<stdlib.h>

using namespace std;

int visit[22] = { 0 }, num[22] = {0};
int n, r;


void dfs(int depth)
{
	if (depth > r)
	{
		cout << num[1];
		for (int i = 2; i <= r; i++)
			cout << " " << num[i];
		cout << endl;
	}
	
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && i > num[depth-1])//第二个条件保证了有序。
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
	cin >> n >> r;
	dfs(1);

	system("pause");
	return 0;
}