#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

#define Max_Node_size 100

typedef char Type;
typedef Type BiTree[Max_Node_size];


typedef struct {
	int depth;//节点所在层数
	int order;//节点在本层的序号
}Position;

void InitTree(BiTree T);//构造空二叉树
void ClearTree(BiTree T);//清空二叉树
bool TreeEmpty(BiTree T);//判断二叉树是否为空
bool CreateBiTree_Pre(BiTree T, int i);//先序构造二叉树
int TreeLength(BiTree T);//返回二叉树长度
int TreeDepth(BiTree T);//返回二叉树深度
bool Root(BiTree T, Type *e);//用 e 返回二叉树的根
Type Value(BiTree T, Position s);//返回二叉树某位置的节点值
bool Assign(BiTree T, Position s, Type value);//为树中某位置的几点赋值
Type Parent(BiTree T, Type e);//返回某节点的双亲
Type LeftChild(BiTree T, Type e);//返回左孩子
Type RightChild(BiTree T, Type e);//返回右孩子
Type LeftSibling(BiTree T, Type e);//返回左兄弟
Type RightSibling(BiTree T, Type e);//返回右兄弟
void LevelOrderTraverse(BiTree T);//层序遍历二叉树
void PreOrderTraverse(BiTree T, int i);//前序遍历二叉树
void InOrderTraverse(BiTree T, int i);//中序遍历二叉树
void PostOrderTraverse(BiTree T, int i);//后序遍历二叉树
void Print(BiTree T);//按二叉树的结构打印树
