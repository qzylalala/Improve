#include<bits/stdc++.h> 
using namespace std;
int main() {
    int n, m, t = 0, d = 0, e = 0;
    cin >> n;
    bool f[n] = {};//�洢�����Ƿ���ƻ������
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> m >> a;
        while (--m) {
            cin >> b;
            if (b <= 0) {//�����������
                a += b;
            } else {
                if (a > b)  //��ƻ������
                    f[i] = true;
                a = b;
            }
        }
        t += a;//�洢���յ���ƻ����
    }
    d = count(f, f + n, true);//�����ж��ٿù�����ƻ������
    for (int i = 0; i < n; ++i) //ͳ������3��ƻ������ƻ�����������
        if (f[i] && f[(i + 1) % n] && f[(i + 2) % n])
            ++e;
    cout << t << " " << d << " " << e;
    return 0;
}

