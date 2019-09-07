#include<iostream>

using namespace std;

int MaxSum(int n, int *a)
{
	int sum = 0, b = a[0];
	for (int i = 1; i < n; i++)
	{
		if (b > 0)
			b += a[i];
		else
			b = a[i];
		if (b > sum)
			sum = b;
	}
	return sum;
}

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	cout << "最大子段和为：" << MaxSum(10, a) << endl;;

	system("pause");
	return 0;
}