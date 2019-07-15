#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int r, y, g, n, k, t, sum = 0;
    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &k, &t);
        if (k == 0) sum += t;
        else if(k == 1) sum += t;
        else if(k == 2) sum += t + r;
        else sum += 0;
    }
    cout << sum << endl;
}
