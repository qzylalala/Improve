#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,m;
int val[15],map[13][13];
int dp[1<<13][13][13];  //dp[state][i][j]��ʾstate״̬�µ����ڶ�����Ϊi�����һ����Ϊjʱ�����Ž⣬ stateΪ�����Ʊ�ʾ�� ������λ��Ӧ��i�������Ƿ��ѱ�visit
long long num[1<<13][13][13];   //num[state][i][j]Ϊ��Ӧ��·����Ŀ

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&val[i]);
        memset(map,0,sizeof(map));
        int u,v;
        while(m--){
            scanf("%d%d",&u,&v);
            u--;v--;
            map[u][v]=map[v][u]=1;
        }
        if(n==1){
            printf("%d 1\n",val[0]);
            continue;
        }
        memset(dp,-1,sizeof(dp));
        memset(num,0,sizeof(num));
        //����Ϊ��ʼ׼������

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j && map[i][j]){
                    dp[(1<<i)|(1<<j)][i][j]=val[i]+val[j]+val[i]*val[j];
                    num[(1<<i)|(1<<j)][i][j]=1;
                }
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<n;j++)
                if((i&(1<<j))!=0)
                    for(int k=0;k<n;k++)
                        if(map[j][k] && j!=k && (i&(1<<k))!=0 && dp[i][j][k]!=-1)   //�����ע�⣬�ȳ������׸�dp[][][]�ľ��庬�壬
                            for(int x=0;x<n;x++)
                                if(map[k][x] && j!=x && k!=x && (i&(1<<x))==0){
                                    int tmp=dp[i][j][k]+val[x]+val[k]*val[x];
                                    if(map[j][x])
                                        tmp+=val[j]*val[k]*val[x];
                                    if(dp[i|(1<<x)][k][x]<tmp){
                                        dp[i|(1<<x)][k][x]=tmp;
                                        num[i|(1<<x)][k][x]=num[i][j][k];
                                    }else if(dp[i|(1<<x)][k][x]==tmp)
                                        num[i|(1<<x)][k][x]+=num[i][j][k];
                                }
        int ans1=0;
        long long ans2=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j && map[i][j]){
                    if(ans1<dp[(1<<n)-1][i][j]){
                        ans1=dp[(1<<n)-1][i][j];
                        ans2=num[(1<<n)-1][i][j];
                    }else if(ans1==dp[(1<<n)-1][i][j])
                        ans2+=num[(1<<n)-1][i][j];
                }
        cout<<ans1<<" "<<ans2/2<<endl;
    }
    return 0;
}
