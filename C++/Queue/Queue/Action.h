#include<iostream>
#define MAXSIZE 100
typedef int datatype;


using namespace std;


typedef struct
{
	datatype data[MAXSIZE];
	int front, rear;//front为头指针， rear为尾指针
}Queue;


bool Set_NULL(Queue &Q);//置空队列
bool Is_NULL(Queue &Q);//判断队列是否为空
bool En_Queue(Queue &Q, datatype a);//入队
bool De_Queue(Queue &Q);//出队
bool show(Queue Q);//显示队列元素
int QueueLength(Queue Q);//求队列的长度
datatype front_element(Queue Q);//取队列头元素


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