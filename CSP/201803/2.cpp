#include<iostream>
#include<algorithm>
#include<map>
 
using namespace std;
 
const int N=100;
int a[N];  //��¼��ʼλ�� 
int ans[N]; //��¼����λ��
int tmp[N]; //ͨ�� tmp����ʹ������С��ĳ�ʼλ�ú�����λ�����Ӧ 
 
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
	sort(tmp,tmp+n);//��С��Ŀ�ʼλ�ý������� 
	sort(ans,ans+n); //��С������λ�ý������� 
	for(int i = 0; i < n; i++)
		dic[tmp[i]] = i;
	
	for (int i = 0; i < n; i++)
		cout << ans[dic[a[i]]] << " "; 
	
	return 0;
}
