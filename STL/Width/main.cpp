#include<cstdio>
#include<cstring>
using namespace std;
const int N = 50;
int n, ans, h[N], vis[N], a[N], d[N][N], p[N];//d[][]为邻接矩阵

void dfs(int cur, int band)//cur表示当前节点序数， ans记录当前找到的最小带宽
{
    if(cur >= n && band < ans)
    {
        ans = band;
        for(int i = 0; i < cur; ++i)
            p[i] = a[i];//p数组记录最优解路径
    }

    for(int i = 0; cur < n && i < 26; ++i)
    {
        if(vis[i] || !h[i])
            continue;

        a[cur] = i , vis[i] = 1;
        for(int j = 0; j < cur; ++j)
            if(d[i][a[j]] && band < cur - j)
                band = cur - j;

        if(band > ans)
        {
            vis[i] = 0;
            return;
        }//剪枝
        dfs(cur + 1, band);
        vis[i] = 0;
    }
}

int main()
{
    char s[N];
    while(scanf("%s", s), strcmp(s, "#"))
    {
        memset(d, 0, sizeof(d));
        memset(h, 0, sizeof(h));
        //h数组记录字母'A'+i是否在图中出现  n为顶点个数
        int i = n = 0, u, v;
        while(s[i])
        {
            u = s[i] - 'A';
            if(!h[u]) h[u] = ++n;
            i += 2;
            while(s[i] && s[i] != ';')
            {
                v = s[i++] - 'A';
                if(!h[v]) h[v] = ++n;
                d[u][v] = d[v][u] =  1;
            }
            if(!s[i++]) break;
        }

        ans = N;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0);
        for(int i = 0; i < n; ++i)
            printf("%c ", 'A' + p[i]);
        printf("-> %d\n", ans);
    }
    return 0;
}


/*sample input

A:FB;B:GC;D:GC;F:AGH;E:HD
#

*/

/*sample output

A B C F G D H E -> 3

*/

