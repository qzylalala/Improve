/*http://codeup.cn/problem.php?id=1130*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 450*105;
int dp[105][maxn], a[105], n;
int main()
{
    while(~scanf("%d", &n))
    {
        memset(dp, 0, sizeof(dp));
        int limit1, limit2, sum = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum += a[i];
        limit1 = n/2;
        limit2 = n/2 + n%2;
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = i; j >= 1; j--)
                for(int v = sum; v >= a[i]; v--)
                    if(dp[j-1][v-a[i]]) dp[j][v] = 1;
        int temp = 1e9;
        int k = sum/2+1;
        while(k--)
        {
            if(dp[limit1][k] || dp[limit2][k])
                break;
        }
        printf("%d %d\n", k, sum-k);
    }
    return 0;
}
