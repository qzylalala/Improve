#include<stdio.h>
#define MAX 90
int S[MAX];
int n,L;
int dfs(int cur)	//����0��ʾ�Ѿ��õ���
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
		int ok=1;	//�жϷ����Ƿ�Ϸ�
		S[cur]=i;	//����ǰλ���趨Ϊi��0==A��1==B��2==C��

		for(j=1;2*j<=cur+1;j++)	//ѭ���жϳ��ȳ���Ϊj*2�ĺ�׺
		{
			int equal=1;	//�жϺ�׺���Ƿ���ǰһ���Ƿ���ں�һ��
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
			if(!dfs(cur+1))	//�����˵��0��curλ�õ����Ѵ��Ѿ�ȷ�����ˣ�ȷ����һ��λ�þͺ�
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
