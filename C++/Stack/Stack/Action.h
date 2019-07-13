#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 0xffff

template<class type>
class my_stack
{
	int top;
	type *my_s;
	int maxsize;

public:
	my_stack() :top(-1), maxsize(MAXSIZE)
	{
		my_s = new type[maxsize];
		if (my_s == NULL)
		{
			cerr << "¶¯Ì¬´æ´¢·ÖÅäÊ§°Ü!" << endl;
			exit(1);
		}
	}
	my_stack(int size) :top(-1), maxsize(size)
	{
		my_s = new type[maxsize];
		if (my_s == NULL)
		{
			cerr << "¶¯Ì¬´æ´¢·ÖÅä´íÎó" << endl;
			exit(1);
		}
	}
	my_stack()
	{
		delete[] my_s;
	}
	
	bool IsEmpty();//ÅÐ¶Ï¶ÑÕ»ÊÇ·ñÎª¿Õ
	void push(type tp);//Ñ¹Õ»
	type Top();//·µ»ØÕ»¶¥ÔªËØ
	void pop();//³öÕ»
	int StackSize();//·µ»Ø¶ÑÕ»´óÐ¡
};


template<class type>
bool my_stack<type>::IsEmpty()
{
	if (top == 1)
		return true;
	else
		return false;
}

template<class type>
type my_stack<type>::Top()
{
	if (top != 1)
	{
		return my_s[top];
	}
	else
	{
		cout << "Õ»¿Õ\n";
		exit(1);
	}
}

template<class type>
void my_stack<type>::push(type tp)
{
	if (top + 1 < maxsize)
	{
		my_s[++top] = tp;
	}
	else
	{
		cout << "Õ»Âú\n";
		exit(1);
	}
}

template<class type>
void my_stack<type>::pop()
{
	if (top >= 0)
		top--;
	else
	{
		cout << "Õ»¿Õ\n";
		exit(1);
	}
}

template<class type>
int my_stack<type>::StackSize()
{
	return top + 1;
}