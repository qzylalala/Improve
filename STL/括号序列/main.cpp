#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[105];
int dp[101][101];//i到j之间加成为regular brackets sequence需要加入的最少字符数
int tag[101][101];//用来做标记 记录最少字符时的是那种情况
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
            dp[i][i]=1;//初始
            dp[i+1][i]=0;//下面在进行DP时，i=j+1时，i=i+1、j=j-1会造成i=j+1
        }
        for (int st=1;st<len;st++)
        {
            for (int i=0;i+st<len;i++)
            {
                int j=i+st;
                int temp=9999999;
                if ((str[i]=='(' && str[j]==')')||(str[i]=='[' && str[j]==']'))
                {
                    temp=dp[i+1][j-1];//第一种情况（s）或[s]
                }
                tag[i][j]=-1;
                for (int k=i;k<j;k++)//第二种情况，枚举i到j之间的k 即AB
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
        print(0,len-1);//根据标记情况进行回溯
        printf("\n");
    }
    return 0;
}
