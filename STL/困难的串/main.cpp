#include<stdio.h>
#define MAX 90
int S[MAX];
int n,L;
int dfs(int cur)	//返回0表示已经得到解
{
	int i,j,k;
	if(cur == n)
	{
		for(i=0;i<cur;i++)
		{
			printf("%c",'A'+S[i]);
		}
		printf("\n");
		return 0;
	}
	for(i=0;i<L;i++)
	{
		int ok=1;	//判断方案是否合法
		S[cur]=i;	//将当前位置设定为i“0==A，1==B，2==C”

		for(j=1;2*j<=cur+1;j++)	//循环判断长度长度为j*2的后缀
		{
			int equal=1;	//判断后缀中是否有前一半是否等于后一半
			for(k=0;k<j;k++)
			{
				if(S[cur-k]!=S[cur-k-j])
				{
					equal=0;
					break;
				}
			}
			if(equal)
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			if(!dfs(cur+1))	//到这里，说明0到cur位置的困难串已经确立好了，确立下一个位置就好
				return 0;
		}
	}
	return 1;
}
int main()
{
	while(scanf("%d%d",&n,&L)!=EOF)
	{
		dfs(0);
	}
	return 0;
}
