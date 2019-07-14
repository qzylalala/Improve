#include<iostream>
#include<stdlib.h>


using namespace std;


template<typename T>
void merge(T* List, int low, int mid, int high)//merge �������Խ�������������ϲ�Ϊһ����������
{
	int i = lo, j = mid + 1;
	T aux[];

	for (int k = low; k <= high; k++)
	{
		aux[k] = List[k];
	}

	for (int k = low; k <= high; k++)
	{
		if (i > mid) List[k] = aux[j++];
		else if (j > hi) List[k] = aux[i++];
		else if (aux[j] < aux[i]) List[k] = aux[j++];
		else List[k] = aux[i++];
	}
}
//�鲢��������˷��ε�˼�룬 �Ƚ�С�����������Ȼ����й鲢���������յõ����������(����С���飬 ���������ǱȽϺõ�ѡ��)
//
/*
void sort(T* List)
{
	int N = List.length;
	T* aux;
	for (int sz = 1; sz < N; sz = sz + sz)
	{
		for (int low = 0; low < N - sz; low += sz + sz)
		{
			merge(a, low, low+sz-1, min(low+sz+sz-1, N - 1))      sz = 1ʱ(0, 0, 1), (2, 2, 3), (4, 4, 5) ......
		}
	}
}
*/