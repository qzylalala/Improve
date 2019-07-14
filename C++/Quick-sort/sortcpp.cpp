#include<stdlib.h>
#include<iostream>
template <typename T>


void partition(T* List, int low, int high)
{
	int i = low, j = high + 1;
	T v = List[low];
	while (true)
	{
		while (List[i++] < v)
			if (i == high)
				break;
		while (List[j--] > v)
			if (j == low)
				break;
		if (i >= j) break;
		swap(List, i, j);//交换List中第i个和第j个元素
	}
	swap(List, j, low);
}
//partition将数组分为两部分，左侧小于中间值，右侧大于中间值。 再两侧小规模数组排序即可
