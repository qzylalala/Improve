#include<cstdio>
#include<stdlib.h>

typedef int T;

typedef struct LNode{
	T data;
	struct LNode* next;
};
typedef LNode* LinkList;

bool InitList(LinkList *L);//初始化链表(指向空指针)
bool ClearList(LinkList L);//清空链表
void DestroyList(LinkList *L);//销毁链表
bool ListEmpty(LinkList L);//判断链表是否为空
int ListLength(LinkList L);//返回链表长度
bool GetElem(LinkList L, int i, T* e);//获取第i个struct的data， 并赋值给e
int locate(LinkList L, T e);//定位data为e的struct的位置
bool PriorElem(LinkList L, T cur_e, T *pre_e);//获得data为cur_e的前一个struct的data值， 赋值给pre_e
bool NextElem(LinkList L, T cur_e, T *next_e);//获得data为cur_e的后一个struct的data值, 赋值给next_e
bool ListInsert(LinkList L, int i, T e);//在第i个struct位置插入一个data为e的struct
bool ListDelete(LinkList L, int i, T *e);//删除第i个struct， 并将其data值赋值给e
void MergeList(LinkList La, LinkList Lb, LinkList Lc);//将data值为非递减的链表La,Lb和并为Lc， Lc也满足data值非递减