#include<stdlib.h>

template <class T>
class Binary_heap
{
	private T* pq;
	private N = 0;

	public void MaxPQ(int MaxN)//创建二叉堆
	{
		pq = new T[MaxN + 1];
	}

	public bool isEmpty()
	{
		return N == 0;
	}

	public int size()
	{
		return N;
	}

	public void insert(T v)//插入新加数值，并维护二叉堆
	{
		pq[++N] = v;
		swim(N);
	}

	public delMax()//删除最大值，并维护二叉堆
	{
		T max = pq[0];
		swap(0, N - 1);
		pq(N - 1) = NULL;
		sink(0);
		return max;
	}

	private int less(int i, int j);//比较函数
	private void swap(int i, int j);//交换函数
	private void sink(int i);//下沉函数
	private void swim(int i);//上浮函数
};


template <class T> int Binary_heap<T>::less(int i, int j)
{
	if (pq[i] < pq[j]) return 1;
	else return 0;
}

template <class T> void Binary_heap<T>::swap(int i, int j)
{
	T t;
	t = pq[i];
	pq[i] = pq[j];
	pq[j] = t;
}

template <class T> void Binary_heap<T>::swim(int i)
{
	while (i > 0 && pq[(i - 1)/2] < pq[i])
	{
		swap(i, (i - 1)/2);
		i = (i - 1)/2;
	}
}

template <class T> void Binary_heap<T>::sink(int i)
{
	while (2*i +  1< N)
	{
		int j = 2 * i + 1;
		if (less(j, j + 1)) j++;
		if (less(i, j)) swap(i, j);
		i = j;
	}
}