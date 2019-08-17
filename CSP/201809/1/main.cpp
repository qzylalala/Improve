#include <iostream>

using namespace std;

int main()
{
    int n, price[1000], new_price[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    new_price[0] = (price[0] + price[1]) / 2;
    new_price[n - 1] = (price[n - 1] + price[n - 2]) / 2;
    for (int i = 1; i < n - 1; i++)
    {
        new_price[i] = (price[i - 1] + price[i] + price[i + 1]) / 3;
    }

    for (int i = 0; i < n; i++)
    {
        cout << new_price[i] << " ";
    }

    return 0;
}
