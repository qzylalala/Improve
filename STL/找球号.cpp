#include<bits/stdc++.h>
 
using namespace std;
  
map<int ,int> ball;//全局变量自动赋初值为0  

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
        if(ball.count(a))  //返回指定元素出现的次数 
            puts("YES");  
        else  
            puts("NO");  
    } 
    
    return 0;
}         
