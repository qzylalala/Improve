#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

#define Max_Node_size 100

typedef char Type;
typedef Type BiTree[Max_Node_size];


typedef struct {
	int depth;//�ڵ����ڲ���
	int order;//�ڵ��ڱ�������
}Position;

void InitTree(BiTree T);//����ն�����
void ClearTree(BiTree T);//��ն�����
bool TreeEmpty(BiTree T);//�ж϶������Ƿ�Ϊ��
bool CreateBiTree_Pre(BiTree T, int i);//�����������
int TreeLength(BiTree T);//���ض���������
int TreeDepth(BiTree T);//���ض��������
bool Root(BiTree T, Type *e);//�� e ���ض������ĸ�
Type Value(BiTree T, Position s);//���ض�����ĳλ�õĽڵ�ֵ
bool Assign(BiTree T, Position s, Type value);//Ϊ����ĳλ�õļ��㸳ֵ
Type Parent(BiTree T, Type e);//����ĳ�ڵ��˫��
Type LeftChild(BiTree T, Type e);//��������
Type RightChild(BiTree T, Type e);//�����Һ���
Type LeftSibling(BiTree T, Type e);//�������ֵ�
Type RightSibling(BiTree T, Type e);//�������ֵ�
void LevelOrderTraverse(BiTree T);//�������������
void PreOrderTraverse(BiTree T, int i);//ǰ�����������
void InOrderTraverse(BiTree T, int i);//�������������
void PostOrderTraverse(BiTree T, int i);//�������������
void Print(BiTree T);//���������Ľṹ��ӡ��
