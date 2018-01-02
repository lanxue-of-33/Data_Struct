#pragma once
#include<iostream>
#include<string.h>
typedef int InfoType;
typedef int KeyType;
#define MAX 100
using namespace std;

//�������ڵ����͵�����
typedef struct node   //Ԫ������
{
	KeyType key;       //�ؼ�����
	InfoType data;     //����������
	struct node*lchild, *rchild;//���Һ���ָ��
}BSTNode;

//�������Ĳ���ʹ���
bool InsertBST(BSTNode *&bt, KeyType k)
{ //�ڶ����������в���һ���ؼ���Ϊk�Ľ�㣬�����ɹ��򷵻��棬���򷵻ؼ�

	if (bt == NULL)  //��ԭ��Ϊ�գ����²���Ľ��Ϊ�����
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key)  //��Ҫ����Ľ���Ѿ����ڣ��򷵻ؼ�
		return false;
	else if (k<bt->key)
		return InsertBST(bt->lchild, k); //����С������뵽������֮��
	else
		return InsertBST(bt->rchild, k); //����������뵽������֮��
}

//����һ�Ŷ������������ӹؼ�������a[0..n-1]��ʼ����
BSTNode *CreateBST(KeyType A[], int n)
{  //����BST�������ָ��

	BSTNode *bt = NULL; //��ʼʱbtΪ����
	int i = 0;
	while (i<n)
	{
		InsertBST(bt, A[i]); //���ؼ���A[i]���뵽������������
		i++;
	}
	return bt;
}

//�����������Ĳ���
BSTNode *SearchBST(BSTNode *bt, KeyType k)
{
	if (bt == NULL || bt->key == k)  //�ݹ��������
		return bt;
	if (k<bt->key)
		return SearchBST(bt->lchild, k);  //���������еݹ����
	else
		return SearchBST(bt->rchild, k);  //���������ֵݹ����
}

///�ݹ����
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
		cout <<"����������Ҫ���ҵ�Ԫ�أ�";
}


//�ǵݹ����
void Non_recursion_search(BSTNode*bt,KeyType k)
{
	BSTNode*p = bt;
	if (p == NULL)
		cout << "����һ��������������ѡ��һ������" << endl;
	while (1) {
		if (p->key == k)
		{
			cout << k << "(�⼴������Ҫ���ҵ�ֵ��";
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

//�����ŷ����������
void DisplayTree(BSTNode *bt)
{
	if (bt != NULL)
	{
		cout << bt->key;
		if (bt->lchild != NULL||bt->rchild != NULL)
		{
			cout << "(";
			DisplayTree(bt->lchild); //����������
			if (bt->rchild != NULL) cout << ",";//���Һ��ӽ��ʱ�Ż��������
			DisplayTree(bt->rchild);
			cout << ")";
		}
	}
}