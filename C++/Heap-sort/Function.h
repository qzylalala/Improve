#include<cstdio>
#include<algorithm>

template <typename T> void swap(T* List, int i, int j)
{
	T t = List[i];
	List[i] = List[j];
	List[j] = t;
}


//���������һ��ʼ
template <typename T> void sink(T* List, int k, int N)
{
	while (2 * k < N)
	{
		int j = 2 * k;
		if (j < N && List[j] < List[j + 1]) j++;
		if (List[j] < List[k])
			swap(List, j, k);
		else
			break;
		k = j;
	}
}


//����Ҳ�������1��ʼ
template <typename T> void heap_sort(T *List)
{
	int N = List.length;//α���룬 java��������ܣ� c++û��
	for (int k = N / 2; k >= 1; k--)
		sink(List, k, N);
	while (N > 1)
	{
		swap(List, 1, N--);
		sink(list, 1, N);
	}

}