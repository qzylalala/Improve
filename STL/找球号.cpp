#include<bits/stdc++.h>
 
using namespace std;
  
map<int ,int> ball;//ȫ�ֱ����Զ�����ֵΪ0  

int main()  
{  
    int m,n,a;  
    cin >> m >> n;
	  
    while(m--)  
    {  
        cin >> a; 
        ball[a] = 1;  
    }  
    
	while(n--)  
    {  
        cin >> a;  
        if(ball.count(a))  //����ָ��Ԫ�س��ֵĴ��� 
            puts("YES");  
        else  
            puts("NO");  
    } 
    
    return 0;
}         
