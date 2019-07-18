#include<cstdio>
#include<stdlib.h>

typedef int T;

typedef struct LNode{
	T data;
	struct LNode* next;
};
typedef LNode* LinkList;

bool InitList(LinkList *L);//��ʼ������(ָ���ָ��)
bool ClearList(LinkList L);//�������
void DestroyList(LinkList *L);//��������
bool ListEmpty(LinkList L);//�ж������Ƿ�Ϊ��
int ListLength(LinkList L);//����������
bool GetElem(LinkList L, int i, T* e);//��ȡ��i��struct��data�� ����ֵ��e
int locate(LinkList L, T e);//��λdataΪe��struct��λ��
bool PriorElem(LinkList L, T cur_e, T *pre_e);//���dataΪcur_e��ǰһ��struct��dataֵ�� ��ֵ��pre_e
bool NextElem(LinkList L, T cur_e, T *next_e);//���dataΪcur_e�ĺ�һ��struct��dataֵ, ��ֵ��next_e
bool ListInsert(LinkList L, int i, T e);//�ڵ�i��structλ�ò���һ��dataΪe��struct
bool ListDelete(LinkList L, int i, T *e);//ɾ����i��struct�� ������dataֵ��ֵ��e
void MergeList(LinkList La, LinkList Lb, LinkList Lc);//��dataֵΪ�ǵݼ�������La,Lb�Ͳ�ΪLc�� LcҲ����dataֵ�ǵݼ�