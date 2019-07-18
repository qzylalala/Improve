#include "Action.h"

bool InitList(LinkList *L)
{
	L = (LinkList *)malloc(sizeof(LNode));
	if (!L)
		return false;
	(*L)->next = NULL;

	return true;
}

bool ClearList(LinkList L)
{
	LinkList pre, p;

	pre = L->next;
	while (pre)
	{
		p = pre->next;
		free(pre);
		pre = p;
	}

	L->next = NULL;
	return true;
}

void DestroyList(LinkList *L)
{
	LinkList p = *L;

	while (p)
	{
		p = (*L)->next;
		free(L);
		(*L) = p;
	}
}

bool ListEmpty(LinkList L)
{
	if (L != NULL && L->next == NULL)
		return true;
	else
		return false;
}

int ListLength(LinkList L)
{
	LinkList p;
	int i = 0;
	if (L)
	{
		p = L->next;
		while (p)
		{
			i++;
			p = p->next;
		}
	}

	return i;
}

bool GetElem(LinkList L, int i, T *e)
{
	int j = 1;
	LinkList p = L->next;

	while (p && j < i)
	{
		j++;
		p = p->next;
	}

	if (!p)
		return false;

	*e = p->data;
	return true;
}

int LocateElem(LinkList L, T e)
{
	int i = 0;
	LinkList p;

	if (L)
	{
		p = L->next;

		while (p)
		{
			i++;
			if (p->data != e)
				p = p->next;
			else
				break;
		}
	}

	if (p == NULL)
		return -1;
	else
		return i;
}

bool PriorElem(LinkList L, T cur_e, T *pre_e)
{
	LinkList p, q;
	if (L)
	{
		p = L->next;

		if (p->data != cur_e)
		{
			while (p->next)
			{
				q = p->next;
				if (q->data == cur_e)
				{
					*pre_e = p->data;
					return true;
				}
				p = q;
			}
		}
	}

	return false;
}

bool NextElem(LinkList L, T cur_e, T *next_e)
{
	LinkList p, q;
	if (L)
	{
		p = L->next;

		while (p && p->next)
		{
			q = p->next;

			if (p->data == cur_e)
			{
				*next_e = q->data;
				return true;
			}
			else
				p = q;
		}
	}

	return false;
}

bool ListInsert(LinkList L, int i, T e)
{
	LinkList p = L, q;
	int j = 0;

	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}

	if (!p)
		return false;
	q = (LinkList)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;

	return true;
}

bool Delete(LinkList L, int i, T *e)
{
	LinkList pre = L, p;
	int j = 1;

	while (pre->next && j < i)
	{
		pre = pre->next;
		j++;
	}

	if (!pre->next)
		return false;

	p = pre->next;
	*e = p->data;
	pre->next = p->next;
	free(p);

	return true;
}

void MergeList(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList pa, pb, pc;
	pa = La->next; pb = Lb->next;
	Lc = pc = La;

	while (pa && pb)
	{
		if (pa->data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
	}

	pa->next = pa ? pa : pb;
	free(Lb);
}