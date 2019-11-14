#include<bits/stdc++.h> 
using namespace std;
int main() {
    int n, m, t = 0, d = 0, e = 0;
    cin >> n;
    bool f[n] = {};//存储果树是否有苹果掉落
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> m >> a;
        while (--m) {
            cin >> b;
            if (b <= 0) {//进行疏果操作
                a += b;
            } else {
                if (a > b)  //有苹果掉落
                    f[i] = true;
                a = b;
            }
        }
        t += a;//存储最终的总苹果数
    }
    d = count(f, f + n, true);//计算有多少棵果树有苹果掉落
    for (int i = 0; i < n; ++i) //统计连续3棵苹果树有苹果掉落的组数
        if (f[i] && f[(i + 1) % n] && f[(i + 2) % n])
            ++e;
    cout << t << " " << d << " " << e;
    return 0;
}

