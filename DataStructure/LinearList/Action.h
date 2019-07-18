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

bool InitList(List *L);//��ʼ�������б�
void ClearList(List *L);//������б�
void DestroyList(List *L);//�������б�
bool ListEmpty(List L);//�ж����б��Ƿ�Ϊ��
int ListLength(List L);//�������б���(Ԫ�ظ���)
bool GetElem(List L, int i, LElemType *e);//��e�������б��i��Ԫ��
int LocateElem(List L, LElemType e);//����e�������� �������ڣ� �򷵻�0
bool PriorElem(List L, LElemType cur_e, LElemType *pre_e);//��pre_e����cur_e��ǰ��
bool NextElem(List L, LElemType cur_e, LElemType *next_e);//��next_e����cur_e�ĺ��
bool ListInsert(List *L, int i, LElemType e);//�����б��i��λ���ϲ���e
bool ListDelete(List *L, int i, LElemType *e);//ɾ�����б��ϵ�i��λ�õ�Ԫ��,������e�洢ɾ��Ԫ��

void Union(List *A, List B);//�ϲ�List A��B
void MergeList(List A, List B, List *C);//C = A +B; A,B,CΪ�ǵݼ�����
