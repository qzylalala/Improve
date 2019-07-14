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
		swap(List, i, j);//����List�е�i���͵�j��Ԫ��
	}
	swap(List, j, low);
}
//partition�������Ϊ�����֣����С���м�ֵ���Ҳ�����м�ֵ�� ������С��ģ�������򼴿�
