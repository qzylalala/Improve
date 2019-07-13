//对数组从小到大排序
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


template <class type> class Sort {

public:
	void BubbleSort(type List[]);//冒泡排序
	void SelectSort(type List[]);//选择排序
	void InsertSort(type List[]);//插入排序
	//void HeapSort(type List[]);//堆排序
	void ShellSort(type List[]);//希尔排序
};


//bubble sort defination
template<class type> void Sort<type>::BubbleSort(type List[])
{
	int N = List.length;
	type t;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (List[j] < List[i])
			{
				t = List[i];
				List[i] = List[j];
				List[j] = t;
			}
		}
		
	}
}


//select sort defination
template<class type> void Sort<type>::SelectSort(type List[])
{
	int N = List.length;
	for (int i = 0; i < N; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < N; j++)
		{
			if (List[j] < List[i])
			{
				min_index = j;
			}
		}
		type t;
		t = List[i];
		List[i] = List[min_index];
		List[min_index] = t;
	}
}


//insert sort
template<class type> void Sort<type>::InsertSort(type List[])
{
	int N = List.length;
	for (int i = 0; i < N; i++)
	{
		type t;
		for (int j = i; j > 0 && List[j] < List[j - 1]; j--)
		{
			t = List[j];
			List[j] = List[j - 1];
			List[j - 1] = t;
		}
	}
}


//shell sort
template<class type> void Sort<type>::ShellSort(type List[])
{
	int N = List.length;
	int h = 1;
	while (h < N / 3)
		h = 3 * h + 1;//这样h取值为确定的一系列数值
	while (h >= 1) 
	{
		for (int i = h; i < N; i++)
		{
			type t;
			for (int j = i; j >=h && List[j] < List[j - h]; j -= h)
			{
				t = List[j];
				List[j] = List[j - h];
				List[j - h] = t;
			}
		}
		h = h / 3;
	}
}