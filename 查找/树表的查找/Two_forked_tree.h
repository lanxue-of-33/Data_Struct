#pragma once
#include<iostream>
#include<string.h>
typedef int InfoType;
typedef int KeyType;
#define MAX 100
using namespace std;

//二叉树节点类型的声明
typedef struct node   //元素类型
{
	KeyType key;       //关键字项
	InfoType data;     //其他数据域
	struct node*lchild, *rchild;//左右孩子指针
}BSTNode;

//二叉树的插入和创建
bool InsertBST(BSTNode *&bt, KeyType k)
{ //在二叉排序树中插入一个关键字为k的结点，如插入成功则返回真，否则返回假

	if (bt == NULL)  //若原树为空，则新插入的结点为根结点
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key)  //若要插入的结点已经存在，则返回假
		return false;
	else if (k<bt->key)
		return InsertBST(bt->lchild, k); //若更小，则插入到左子树之中
	else
		return InsertBST(bt->rchild, k); //若更大，则插入到右子树之中
}

//创建一颗二叉排序树，从关键字数组a[0..n-1]开始生成
BSTNode *CreateBST(KeyType A[], int n)
{  //返回BST树根结点指针

	BSTNode *bt = NULL; //初始时bt为空树
	int i = 0;
	while (i<n)
	{
		InsertBST(bt, A[i]); //将关键字A[i]插入到二叉排序树中
		i++;
	}
	return bt;
}

//二叉排序树的查找
BSTNode *SearchBST(BSTNode *bt, KeyType k)
{
	if (bt == NULL || bt->key == k)  //递归结束条件
		return bt;
	if (k<bt->key)
		return SearchBST(bt->lchild, k);  //在左子树中递归查找
	else
		return SearchBST(bt->rchild, k);  //在右子树种递归查找
}

///递归查找
void Recursion_search(BSTNode* bt,KeyType k)
{
	if (bt != NULL||bt->key!=k)
	{
		cout << bt->key<<'\t';
		if (k < bt->key)
			Recursion_search(bt->lchild, k);
		if (k > bt->key)
			Recursion_search(bt->rchild, k);
	}
	if (bt->key==k)
		cout <<"（这是我们要查找的元素）";
}


//非递归查找
void Non_recursion_search(BSTNode*bt,KeyType k)
{
	BSTNode*p = bt;
	if (p == NULL)
		cout << "这是一个空链表，请重新选择一个链表！" << endl;
	while (1) {
		if (p->key == k)
		{
			cout << k << "(这即是我们要查找的值）";
			break;
		}
		cout << p->key<<'\t';
		if (k < p->key)
		{
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
	}
}

//用括号法输出二叉树
void DisplayTree(BSTNode *bt)
{
	if (bt != NULL)
	{
		cout << bt->key;
		if (bt->lchild != NULL||bt->rchild != NULL)
		{
			cout << "(";
			DisplayTree(bt->lchild); //处理左子树
			if (bt->rchild != NULL) cout << ",";//有右孩子结点时才会输出逗号
			DisplayTree(bt->rchild);
			cout << ")";
		}
	}
}