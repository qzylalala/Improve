#include "Action.h"

bool InitList(List *L)
{
	(*L).elem = (LElemType *)malloc(List_Init_Size * sizeof(LElemType));
	(*L).length = 0;
	(*L).listsize = List_Init_Size;

	return true;
}

void ClearList(List *L)
{
	(*L).length = 0;
}

void DestroyList(List *L)
{
	free((*L).elem);

	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
}

bool ListEmpty(List L)
{
	if (L.length == 0)
		return true;
	else
		return false;
}

int ListLength(List L)
{
	return L.length;
}

bool GetElem(List L, int i, LElemType *e)
{
	if (i < 1 || i > L.length)
		return false;
	else
	{
		*e = L.elem[i - 1];
		return true;
	}
}

int LocateElem(List L, LElemType e)
{
	int i = 1;
	while (i <= L.length)
	{
		if (L.elem[i - 1] == e)
			return i;
		i++;
	}
	return 0;
}

bool PriorElem(List L, LElemType cur_e, LElemType *pre_e)
{
	int i = 0;
	while (i < L.length)
	{
		if (L.elem[i] != cur_e)
			++i;
		else
		{
			*pre_e = L.elem[i - 1];
			return true;
		}
	}
	if (i >= L.length)
		return false;
}

bool NextElem(List L, LElemType cur_e, LElemType *next_e)
{
	int i = 0;
	while (i < L.length && L.elem[i] != cur_e)
		i++;
	if (i < L.length - 1)
	{
		*next_e = L.elem[i + 1];
		return true;
	}
	else
		return false;
}

bool ListInsert(List *L, int i, LElemType e)
{
	LElemType *newbase;
	LElemType *q, *p;

	if (i < 1 || i >(*L).length)
		return false;
	
	if ((*L).length > (*L).listsize)
	{
		newbase = (LElemType*)realloc((*L).elem, ((*L).listsize + ListIncrease) * sizeof(LElemType);

		(*L).elem = newbase;
		(*L).listsize += ListIncrease;
	}

	q = &(*L).elem[i - 1];
	for (p = &(*L).elem[(*L).length - 1]; p >= q; p--)
	{
		*(p + 1) = *p;
	}

	*q = e;
	(*L).length++;

	return true;
}

bool ListDelete(List *L, int i, LElemType *e)
{
	int j;
	LElemType *q, *p;
	if (i < 1 || i >(*L).length)
	{
		return false;
	}

	p = &(*L).elem[i - 1];
	*e = *p;
	q = (*L).elem + (*L).length - 1;
	for (++p; p <= q; p++)
	{
		*(p - 1) = *p;
	}
	
	(*L).length--;
	return true;
}

void Union(List *A, List B)
{
	int a_len = (*A).length;
	int b_len = B.length;
	LElemType e;
	for (int i = 1; i < b_len; i++)
	{
		GetElem(B, i, &e);
		if (!LocateElem(*A, e))
			ListInsert(A, ++a_len, e);
	}
}

void MergeList(List A, List B, List *C)
{
	LElemType *pa = A.elem;
	LElemType *pb = B.elem;
	LElemType *pc, *pa_last, *pb_last;

	(*C).listsize = (*C).length = A.length + B.length;
	pc = (*C).elem = (LElemType*)malloc((*C).listsize * sizeof(LElemType));
	pa_last = A.elem + A.length - 1;
	pb_last = B.elem + B.length - 1;

	while (pa < pa_last && pb < pb_last)
	{
		if (*pa < *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}

	while (pa < pa_last)
		*pc++ = *pa++;
	while (pb < pb_last)
		*pc++ = *pb++;
}