#include<stdlib.h>

template <class T>
class Binary_heap
{
	private T* pq;
	private N = 0;

	public void MaxPQ(int MaxN)//���������
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

	public void insert(T v)//�����¼���ֵ����ά�������
	{
		pq[++N] = v;
		swim(N);
	}

	public delMax()//ɾ�����ֵ����ά�������
	{
		T max = pq[0];
		swap(0, N - 1);
		pq(N - 1) = NULL;
		sink(0);
		return max;
	}

	private int less(int i, int j);//�ȽϺ���
	private void swap(int i, int j);//��������
	private void sink(int i);//�³�����
	private void swim(int i);//�ϸ�����
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