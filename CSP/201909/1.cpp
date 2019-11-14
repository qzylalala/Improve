#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, t = 0, k = 0, p = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {  //遍历所有苹果树
        int a, b = 0, c;
        cin >> a;  //疏果之前的苹果个数
        t += a;
        for (int j = 0; j < m; ++j) {  //遍历每一轮的疏果个数
            cin >> c;
            b += c;  //累加疏果总数
        }
        t += b;
        if (abs(b) > p) {  //当前苹果树的疏果总数比p大，更新p和k
            k = i;
            p = abs(b);
        }
    }
    cout << t << " " << k << " " << p;
    return 0;
}

