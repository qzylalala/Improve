#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[105];
int dp[101][101];//i��j֮��ӳ�Ϊregular brackets sequence��Ҫ����������ַ���
int tag[101][101];//��������� ��¼�����ַ�ʱ�����������
int len;

void print(int s,int e)
{
    if (s>e)return;
    if (s==e)
    {
        if (str[s]=='(' || str[s]==')')
        {
            printf("()");
        }
        else
        {
            printf("[]");
        }
        return ;
    }
    if (tag[s][e]==-1)
    {
        printf("%c",str[s]);
        print(s+1,e-1);
        printf("%c",str[e]);
    }
    else
    {
        print(s,tag[s][e]);
        print(tag[s][e]+1,e);
    }
}

int main()
{
    while (gets(str))
    {
        len = strlen(str);
        for (int i=0;i<len;i++)
        {
            dp[i][i]=1;//��ʼ
            dp[i+1][i]=0;//�����ڽ���DPʱ��i=j+1ʱ��i=i+1��j=j-1�����i=j+1
        }
        for (int st=1;st<len;st++)
        {
            for (int i=0;i+st<len;i++)
            {
                int j=i+st;
                int temp=9999999;
                if ((str[i]=='(' && str[j]==')')||(str[i]=='[' && str[j]==']'))
                {
                    temp=dp[i+1][j-1];//��һ�������s����[s]
                }
                tag[i][j]=-1;
                for (int k=i;k<j;k++)//�ڶ��������ö��i��j֮���k ��AB
                {
                    int res=dp[i][k]+dp[k+1][j];
                    if (res<temp)
                    {
                        temp=res;
                        tag[i][j]=k;
                    }
                }
                dp[i][j]=temp;
            }
        }
        print(0,len-1);//���ݱ��������л���
        printf("\n");
    }
    return 0;
}
