#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    long long n, i;
    long long List[100000];
    scanf("%lld", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &List[i]);
    }
    if (List[0] < List[n - 1])
    {
        cout << List[n - 1] << ' ';
        if (n % 2 == 1)
            cout << List[n / 2] << ' ' << List[0] << endl;
        else
            cout << (List[n / 2] + List[(n / 2) - 1]) / 2 << ' ' << List[0] << endl;
    }
    else if (List[0] > List[n - 1])
    {
        cout << List[0] << ' ';
        if (n % 2 == 1)
            cout << List[n / 2] << ' ' << List[n - 1] << endl;
        else
            cout << (List[n / 2] + List[(n / 2) - 1]) / 2 << ' ' << List[n - 1] << endl;
    }
    else cout << List[0] << ' ' << List[0] << ' ' << List[0] << endl;
    return 0;
}
