#include<bits/stdc++.h>

using namespace std;

int main(){
	int m, n, i;
	cin >> n;
	while(n--){
		int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		cin >> m;
		do{
			for(i = 0; i < m; i++){
				cout << a[i];
			}
			cout << endl;
		}while(next_permutation(a, a + m));
	}
	//  1. bool next_permutation(iterator start,iterator end)
    //    ����ǰ���в�������һ�����У���������false�����򷵻�true
	//  2.next_permutation(num,num+n)�����Ƕ�����num�е�
	//    ǰn��Ԫ�ؽ���ȫ���У�ͬʱ���ı�num�����ֵ 
	//  3.next_permutation��node,node+n,cmp��
	//    ���ԶԽṹ��num�����Զ��������ʽcmp��������
	return 0;
}         
