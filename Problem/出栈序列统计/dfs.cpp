#include<iostream>

using namespace std;

int n, count_all = 0;
void dfs(int push, int pop, int depth)
{
	if (depth == n)
	{
		count_all++;
		return;
	}
	if (push > 0)
		dfs(push - 1, pop + 1, depth);
	if (pop > 0)
		dfs(push, pop - 1, depth + 1);
}

int main()
{
	cin >> n;
	dfs(n, 0, 0);
	cout << count_all << endl;

	system("pause");
	return 0;
}