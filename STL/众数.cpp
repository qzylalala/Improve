#include<bits/stdc++.h>

using namespace std;  

int main()  
{  
    map<int, int> a;   //���value����Ϊ����һ���Ĭ�ϸ�ֵΪ 0
    int n, m, i, max, key, x;  
    cin >> n;
    while(n--)  
    {  
        max = key = 0;  
        a.clear();  
        cin >> m;  
        for(i = 0 ; i < m ; i++)  
        {  
            scanf("%d", &x);  
            a[x]++;  
            if(a[x] > key)  
            {  
                key = a[x];  
                max = x;  
            }  
        }  
        cout << max << " " << key << endl;
    }  
    return 0;  
}         
