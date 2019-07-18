#include<cstdio>
#include<stdlib.h>

#define List_Init_Size 100
#define ListIncrease 10

typedef int LElemType;

typedef struct
{
	LElemType *elem;
	int length;
	int listsize;
}List;

bool InitList(List *L);//初始化空序列表
void ClearList(List *L);//请空序列表
void DestroyList(List *L);//销毁序列表
bool ListEmpty(List L);//判断序列表是否为空
int ListLength(List L);//返回序列表长度(元素个数)
bool GetElem(List L, int i, LElemType *e);//用e接收序列表第i个元素
int LocateElem(List L, LElemType e);//返回e的序数， 若不存在， 则返回0
bool PriorElem(List L, LElemType cur_e, LElemType *pre_e);//用pre_e接收cur_e的前驱
bool NextElem(List L, LElemType cur_e, LElemType *next_e);//用next_e接收cur_e的后继
bool ListInsert(List *L, int i, LElemType e);//在序列表第i个位置上插入e
bool ListDelete(List *L, int i, LElemType *e);//删除序列表上第i个位置的元素,并将用e存储删除元素

void Union(List *A, List B);//合并List A，B
void MergeList(List A, List B, List *C);//C = A +B; A,B,C为非递减序列
