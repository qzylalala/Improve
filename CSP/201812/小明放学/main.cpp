#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>

using namespace std;
typedef long long ll;
int main()
{
    ll r, y, g, n, k, t, sum = 0;
    scanf("%lld %lld %lld", &r, &y, &g);
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &k, &t);
        if(k == 0)
            sum += t;
        else if(k == 1)
        {
            if(sum < t)
                sum += t-sum;
            else if(((sum-t) % (r+g+y)) <= g)
                sum += 0;
            else
                sum += (r+g+y) - ((sum-t)%(r+g+y));
        }
        else if(k == 2)
        {
            if(sum <= t)
                sum += t - sum + r;
            else if(((sum-t) % (r+g+y)) < r)
                sum += r - ((sum-t) % (r+g+y));
            else if(((sum-t) % (r+g+y)) <= (r + g))
                sum += 0;
            else
                sum += r + (r + g + r) - ((sum-t) % (r+g+y));
        }
        else
        {
            if(sum < t)
                sum += 0;
            else if(((sum - t) % (r+g+y)) < (r + y))
                sum += r + y - ((sum -t) % (r+g+y));
            else
                sum +=0;
        }
    }
    cout << sum << endl;
    return 0;
}
