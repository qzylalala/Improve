#include<bits/stdc++.h>

using namespace std;

int main()
{
     int i, m, n, a;
     long long s,sum,b[12000];
     priority_queue<int, vector<int>, greater<int> > pri_q;//升序 
     cin>>n;
     
     while(n--)
     {
        while(!pri_q.empty())
        	pri_q.pop();
        cin>>m;
        sum=0;
 
        for(i=0;i<m;i++)
        {
           cin>>a;
           pri_q.push(a);
        }
        
        if(m==1)
		{
			cout << a << endl;
			continue;
		}
		
        for(i = 0;i < m-1; i++)
        {
            s = pri_q.top();  pri_q.pop(); // .top() 为队头元素；.pop() 弹出队头元素 
            s += pri_q.top(); b[i]=s; pri_q.pop();
            pri_q.push(s);
        }
        
		for(i = 0; i < m-1; i++)
			sum+=b[i];
         
         cout << sum << endl;
     }
	return 0;
}
