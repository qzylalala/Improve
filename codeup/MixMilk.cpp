/*
#include<iostream>
#include<algorithm>

using namespace std;

struct milk {
	int p;
	int num;
};
milk m[5005];

int cmp(milk a, milk b)
{
	return a.p < b.p;
}

int N, M;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> m[i].p >> m[i].num;
	}
	sort(m, m + M, cmp);
	long long sum = 0;
	int n = N;
	for (int i = 0; i < M&&n != 0; i++)
	{
		if (m[i].num < n)
		{
			sum += m[i].num * m[i].p;
			n -= m[i].num;
		}
		else
		{
			sum += n * m[i].p;
			n = 0;
		}
	}
	cout << sum << endl;
	
	return 0;
}
*/