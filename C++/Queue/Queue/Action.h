#include<iostream>
#define MAXSIZE 100
typedef int datatype;


using namespace std;


typedef struct
{
	datatype data[MAXSIZE];
	int front, rear;//frontΪͷָ�룬 rearΪβָ��
}Queue;


bool Set_NULL(Queue &Q);//�ÿն���
bool Is_NULL(Queue &Q);//�ж϶����Ƿ�Ϊ��
bool En_Queue(Queue &Q, datatype a);//���
bool De_Queue(Queue &Q);//����
bool show(Queue Q);//��ʾ����Ԫ��
int QueueLength(Queue Q);//����еĳ���
datatype front_element(Queue Q);//ȡ����ͷԪ��


bool Set_NULL(Queue &Q)
{
	Q.front = 0;
	Q.rear = 0;
	return true;
}

bool Is_NULL(Queue &Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

bool En_Queue(Queue &Q, datatype a)
{
	if ((Q.rear - Q.front) >= MAXSIZE - 1)
	{
		cout << "The queue is full.";
		return false;
	}
	Q.rear += 1;
	Q.data[Q.rear] = a;
	return true;
}

bool De_Queue(Queue &Q)
{
	if (Is_NULL(Q))
	{
		cout << "The queue is empty.";
		return false;
	}
	Q.front += 1;
	return true;
}

bool show(Queue Q)
{
	if (Is_NULL(Q))
	{
		cout << "The queue is empty.";
		return false;
	}
	for (int i = Q.front; i < Q.rear; i++)
	{
		cout << Q.data[i + 1] << " ";
	}
	return true;
}

int QueueLength(Queue Q)
{
	int count = 0;
	for (int i = Q.front; i < Q.rear; i++)
		count++;
	return count;
}

datatype front_element(Queue Q)
{
	if (Is_NULL(Q))
	{
		cout << "The queue is empty.";
		return false;
	}
	return Q.data[Q.front + 1];
}