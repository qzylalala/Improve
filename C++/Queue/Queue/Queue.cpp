#include "Action.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	Queue Q;
	Set_NULL(Q);   //ÖÃ¿Õ

	if (Is_NULL(Q))   //ÅĞ¶ÏÊÇ·ñÎª¿Õ
	{
		cout << "The queue is empty" << endl;
	}
	else
	{
		cout << "The queue is not empty" << endl;
	}

	En_Queue(Q, 2);
	En_Queue(Q, 5);
	En_Queue(Q, 9);
	En_Queue(Q, 3);
	En_Queue(Q, 2);

	show(Q);
	cout << "\n Queue length is: " << QueueLength(Q);
	De_Queue(Q);
	cout << endl;
	cout << "After the De_queue:";
	show(Q);
	cout << "\n Queue length is: " << QueueLength(Q);

	cout << endl;
	cout << "The front element is:" << front_element(Q);

	system("pause");
	return 0;
}