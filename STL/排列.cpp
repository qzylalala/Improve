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
    //    若当前序列不存在下一个排列，函数返回false，否则返回true
	//  2.next_permutation(num,num+n)函数是对数组num中的
	//    前n个元素进行全排列，同时并改变num数组的值 
	//  3.next_permutation（node,node+n,cmp）
	//    可以对结构体num按照自定义的排序方式cmp进行排序。
	return 0;
}         
