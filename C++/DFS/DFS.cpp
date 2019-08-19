/*代码参考https://www.jianshu.com/p/70952b51f0c8*/

/*递归实现*/
#include <iostream>
#define N 5
using namespace std;
int maze[N][N] = {
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 1 },
	{ 0, 0, 1, 0, 0 },
	{ 1, 1, 0, 0, 1 },
	{ 0, 0, 1, 0, 0 }
};
int visited[N + 1] = { 0, };
void DFS(int start)
{
	visited[start] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && maze[start - 1][i - 1] == 1)
			DFS(i);
	}
	cout << start << " ";
}
int main()
{
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;
		DFS(i);
	}
	return 0;
}



/*非递归实现*/
#include <iostream>
#include <stack>
#define N 5
using namespace std;
int maze[N][N] = {
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 1 },
	{ 0, 0, 1, 0, 0 },
	{ 1, 1, 0, 0, 1 },
	{ 0, 0, 1, 0, 0 }
};
int visited[N + 1] = { 0, };
void DFS(int start)
{
	stack<int> s;
	s.push(start);
	visited[start] = 1;
	bool is_push = false;
	while (!s.empty())
	{
		is_push = false;
		int v = s.top();
		for (int i = 1; i <= N; i++)
		{
			if (maze[v - 1][i - 1] == 1 && !visited[i])
			{
				visited[i] = 1;
				s.push(i);
				is_push = true;
				break;
			}
		}
		if (!is_push)
		{
			cout << v << " ";
			s.pop();
		}

	}
}
int main()
{
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;
		DFS(i);
	}
	return 0;
}