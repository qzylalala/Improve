#include<iostream>
#include<algorithm>
#include<map>
 
using namespace std;
 
const int N=100;
int a[N];  //记录开始位置 
int ans[N]; //记录结束位置
int tmp[N]; //通过 tmp数组使得输入小球的初始位置和最终位置相对应 
 
int main()
{
	map<int,int> dic;
	int n, L, t;
	cin >> n >> L >> t;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		tmp[i] = a[i];
		int temp = a[i] + t;
		temp = temp % (2*L);
		if(temp > L)
		  ans[i] = L - temp % L;
		else
		  ans[i] = temp; 
	}
	sort(tmp,tmp+n);//对小球的开始位置进行排序 
	sort(ans,ans+n); //对小球的最后位置进行排序 
	for(int i = 0; i < n; i++)
		dic[tmp[i]] = i;
	
	for (int i = 0; i < n; i++)
		cout << ans[dic[a[i]]] << " "; 
	
	return 0;
}
