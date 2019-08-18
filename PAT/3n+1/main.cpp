#include <iostream>

using namespace std;
int step = 0;

int solve(int n);
int main()
{
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}

int solve(int n)
{
    if(n == 1)
        return step;
    else{
        if(n % 2 == 0)
            n = n / 2;
        else
            n = (3*n + 1) / 2;
        step += 1;
        solve(n);
    }
}
