#include<cstdio>
#include<cstring>
using namespace std;
const int N = 50;
int n, ans, h[N], vis[N], a[N], d[N][N], p[N];//d[][]Ϊ�ڽӾ���

void dfs(int cur, int band)//cur��ʾ��ǰ�ڵ������� ans��¼��ǰ�ҵ�����С����
{
    if(cur >= n && band < ans)
    {
        ans = band;
        for(int i = 0; i < cur; ++i)
            p[i] = a[i];//p�����¼���Ž�·��
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
        }//��֦
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
        //h�����¼��ĸ'A'+i�Ƿ���ͼ�г���  nΪ�������
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

