#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define max 10001

int main()
{
	int n;
	int weight[max];
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
			cin >> weight[i];
		sort(weight, weight+n);
		long long sum = weight[0];
		long long temp = 0;
		for (int i = 1; i < n; i++)
		{
			if(sum > weight[i])
			{
				int j;
				for (j = i; j < n; j++)
				{
					if (weight[j] < sum)
						weight[j - 1] = weight[j];
					else
					{
						weight[j - 1] = sum;
						break;
					}
				}
				if (j == n)
					weight[n - 1] = sum;
				sum = weight[i - 1];
			}
			if (sum <= weight[i])
			{
				temp = temp + (sum + weight[i]);
				sum += weight[i];
			}
		}

		cout << temp << endl;
	}

	return 0;
}

/*
网上优先队列的使用，妙哉。
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<long long ,vector<long long>,greater<long long>>q;
int main(){
	int n;
	long long temp,x,y,ans = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%lld",&temp);
		q.push(temp);
	}
	while(q.size() > 1){
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x+y);
		ans += x+y;
	}
	printf("%lld\n",ans);
	return 0;
}
链接：https://blog.csdn.net/qq_40073459/article/details/87858479
*/