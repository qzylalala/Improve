#include<cstdio>
#include<algorithm>

using namespace std;
void search_pos(int cur, int n);
int C[10];
int tot = 0;

int main()
{
    int n;
    scanf("%d", &n);
    search_pos(0, n);

    printf("%d", tot);
    return 0;
}

void search_pos(int cur, int n)
{
    if(n == cur) tot++;
    else{
        for (int i = 0; i < n; i++)
        {
            int ok = 1;
            C[cur] = i;
            for(int j = 0; j < cur; j++)
            {
                if(C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok == 1)
                search_pos(cur + 1, n);
        }
    }
}
