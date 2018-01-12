#pragma once
#include<iostream>
#include<stdio.h>
#include <string>
#include "stdlib.h"
#include<Windows.h>
#include<fstream>
using namespace std;

int flag1 = 0;
typedef struct                                          //通讯录结点类型
{
	char num[5];                                            //编号
	char name[9];                                           //姓名
	char sex[3];                                            //性别
	char phone[13];                                         //电话
	char addr[31];                                          //地址
} DataType;
typedef struct node                                     //结点类型定义
{
	DataType data;                                           //结点数据域
	struct node *next;                                       //结点指针域
} ListNode;
typedef ListNode *LinkList;
LinkList head;
ListNode *p;
LinkList CreateList(void);
void InsertNode(LinkList head, ListNode *p);//插入
ListNode *ListFind(LinkList head);//查找
void DelNode(LinkList head);//删除
void PrintList(LinkList head);//输出

//尾插法建立带头结点的通讯录链表算法
LinkList CreateList(void)
{
	LinkList head = (ListNode *)malloc(sizeof(ListNode));         //申请头结点
	ListNode *p, *rear;
	rear = head;                                                //尾指针初始指向头结点
	cout << "请问你需要使用原先的通讯录还是自己新建一个通讯录" << endl;
	cout << "输入1选择使用原来的通讯录，输入2选择自己新建通讯录" << endl;
	int my_choice;
	cin >> my_choice;
	if (my_choice == 1)
	{
		//打开我们的文件进行输入输入
		fstream lianxiren_in;
		lianxiren_in.open("D:\\try\\lianxiren.txt", ios::in);
		if (lianxiren_in.fail())
		{
			cout << "对不起，文件不存在，你只能选择新建通讯录！" << endl;
			return NULL;
		}
		string s1, s2, s3, s4, s5;
		char c1, c2, c3, c4, c5;
		while (lianxiren_in.peek() != EOF)
		{
			p = (ListNode *)malloc(sizeof(ListNode));                     //申新结点
			lianxiren_in >> p->data.num;lianxiren_in.get(c1);
			lianxiren_in >> p->data.name;lianxiren_in.get(c2);
			lianxiren_in >> p->data.sex;lianxiren_in.get(c3);
			lianxiren_in >> p->data.phone;lianxiren_in.get(c4);
			lianxiren_in >> p->data.addr;lianxiren_in.get(c5);
			rear->next = p;                                                 //新结点连接到尾结点之后
			rear = p;                                                        //尾指针指向新结点
		}
		rear->next = NULL;                                                    //终端结点指针置空
		return head;
	}
	else
	{
		char flag = 'y';                                            //int flag=0; 结束标志置 0
		//rear = head;                                                //尾指针初始指向头结点
		//建立一个用于保存联系人信息的输出文件
		fstream inout;
		inout.open("D:\\try\\lianxiren.txt", ios::out | ios::trunc);//建立链表前先清空文件内的所有内容
		inout.close();

		while (flag == 'y')
		{
			inout.open("D:\\try\\lianxiren.txt", ios::out | ios::app);
			p = (ListNode *)malloc(sizeof(ListNode));                     //申新结点
			cout << "\n请输入通讯人员的编号 姓名 性别 电话 地址 :" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\n 编号:";
			cin >> p->data.num;
			cout << "\n 姓名:";
			cin >> p->data.name;
			cout << "\n 性别:";
			cin >> p->data.sex;
			cout << "\n 电话:";
			cin >> p->data.phone;
			cout << "\n 地址:";
			cin >> p->data.addr;
			//输入完联系人信息后将其输出到我们的保存文件之中
			inout << p->data.num << '\t' << p->data.name << '\t' << p->data.sex << '\t' << p->data.phone << '\t' << p->data.addr << '\n';
			inout.close();
			rear->next = p;                                                 //新结点连接到尾结点之后
			rear = p;                                                        //尾指针指向新结点
			cout << "是否继续建表?(请输入y/n):";
			cin >> flag;
		}
		rear->next = NULL;                                                    //终端结点指针置空
		return head;                                                            //返回链表头指针
	}
	
}
//在通讯录链表中插入结点
void InsertNode(LinkList head, ListNode *p)
{
	ListNode *p1, *p2;
	p1 = head;
	p2 = p1->next;
	while (p2 != NULL && strcmp(p2->data.num, p->data.num)<0)
	{
		p1 = p2;                                         //p1 指向刚访问过的结点
		p2 = p2->next;                                   //p2 指向表的下一个结点
	}
	p1->next = p;                                          //插入 p 所指向的结点
	p->next = p2;                                           //连接表中剩余的结点
	fstream aaa;
	aaa.open("D:\\try\\lianxiren.txt", ios::out | ios::trunc);
	/*
	这里有一个神奇的bug：
	当我们添加了ios::app后，就会发现我们无论插入什么结点，都只有创建链表时的结点才会写入，其它后面的任何文件输入语句都不会执行
	当然了，输入时好像是默认文件末尾进行输入，所以这里我们没加ios::app时也没有出错
    后面就是我们的错误代码
	*/
	ListNode *pp = head->next;
	while (pp != NULL) //链表不为空时
	{
	aaa<< pp->data.num << '\t' <<pp->data.name << '\t' <<pp->data.sex << '\t' <<pp->data.phone << '\t' <<pp->data.addr << '\n';
	pp = pp->next;
	}
	aaa.close();
	//打开文件并进行输入
	/*fstream fileout;
	fileout.open("D:\\try\\lianxiren.txt", ios::out |ios::trunc| ios::app); //ios::trunc作用为，如果文件存在，则清空。
	ListNode *pp = head->next;
	/*while (pp != NULL) //链表不为空时
	{
		fileout<< pp->data.num << '\t' <<pp->data.name << '\t' <<pp->data.sex << '\t' <<pp->data.phone << '\t' <<pp->data.addr << '\n';
		pp = pp->next;
	}
	fileout << "测试" << endl;
	fileout.close();*/
}

//在有序通讯录链表中查找 
ListNode *ListFind(LinkList head)
{
	ListNode *p;
	char num[5];
	char name[9];
	char pp;
	cout << "   a. 按编号查询 ";
	cout << "   b. 按姓名查询 " << endl;
	cout << " 请输入您的选择： ";
	p = head->next;
	cin >> pp;
	while (pp != 'a' && pp != 'A' && pp != 'b'&& pp != 'B')
	{
		cout << "对不起，你输入的选择有误，请重新输入你的选择： ";cin >> pp;
	}
	if (pp == 'a' || pp == 'A')
	{
		cout << "请输入通讯人员编号：";
		cin >> num;
		while (p&&strcmp(p->data.num, num) != 0) p = p->next;
		if ((p == NULL)) p = NULL;                                      //没有查到通讯信息
	}
	else if (pp == 'b' || pp == 'B')
	{
		cout << " 请输入通讯人员姓名：";
		cin >> name;
		while (p&&strcmp(p->data.name, name) != 0) p = p->next;
	}
	return p;
}
//通讯录链表上的结点删除
void DelNode(LinkList head)
{
	char cho;
	ListNode *p, *q;
	p = ListFind(head);                                          //调用查找函数
	if (p == NULL)
	{
		cout << "没有查到要删除的通讯人员!";
		return;
	}
	else if (p != NULL)
	{
		cout << "查询成功！ " << endl;
		cout << "通讯人员信息如下： ";
		cout << "-----------------------------------------------" << endl;
		cout << "编 号:" << p->data.num << endl;
		cout << "姓 名:" << p->data.name << endl;
		cout << "性 别:" << p->data.sex << endl;
		cout << "电 话:" << p->data.phone << endl;
		cout << "地 址:" << p->data.addr << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "确定要删除该通讯人员信息？（请输入y/n）:";
		cin >> cho;
		if (cho == 'y' || cho == 'Y')
		{
			q = head;
			while ((q != NULL) && (q->next != p)) q = q->next;
			q->next = p->next;                                                 //删除结点
			free(p);                                                    //释放被删结点空间
			cout << "删除成功！\n";
		}
	}
	fstream aaa;
	aaa.open("D:\\try\\lianxiren.txt", ios::out | ios::trunc);
	ListNode *pp = head->next;
	while (pp != NULL) //链表不为空时
	{
		aaa << pp->data.num << '\t' << pp->data.name << '\t' << pp->data.sex << '\t' << pp->data.phone << '\t' << pp->data.addr << '\n';
		pp = pp->next;
	}
	aaa.close();
}
//通讯录链表的输出函数 
void PrintList(LinkList head)
{
	ListNode *p;
	p = head->next;
	cout << "查询成功！" << endl;
	cout << " 通讯录链表中的所有通讯人员：" << endl;
	cout << "-------------------------------------------------- " << endl;
	while (p != NULL)
	{
		cout << "编 号:" << p->data.num << endl;
		cout << "姓 名:" << p->data.name << endl;
		cout << "性 别:" << p->data.sex << endl;
		cout << "电 话:" << p->data.phone << endl;
		cout << "地 址:" << p->data.addr << endl;
		cout << "-------------------------------------------------- " << endl;
		p = p->next;                                              //后移一个结点
	}
}