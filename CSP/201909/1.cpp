#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, t = 0, k = 0, p = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {  //��������ƻ����
        int a, b = 0, c;
        cin >> a;  //���֮ǰ��ƻ������
        t += a;
        for (int j = 0; j < m; ++j) {  //����ÿһ�ֵ��������
            cin >> c;
            b += c;  //�ۼ��������
        }
        t += b;
        if (abs(b) > p) {  //��ǰƻ���������������p�󣬸���p��k
            k = i;
            p = abs(b);
        }
    }
    cout << t << " " << k << " " << p;
    return 0;
}

