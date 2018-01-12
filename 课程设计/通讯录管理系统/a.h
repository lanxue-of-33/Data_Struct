#pragma once
#include<iostream>
#include<stdio.h>
#include <string>
#include "stdlib.h"
#include<Windows.h>
#include<fstream>
using namespace std;

int flag1 = 0;
typedef struct                                          //ͨѶ¼�������
{
	char num[5];                                            //���
	char name[9];                                           //����
	char sex[3];                                            //�Ա�
	char phone[13];                                         //�绰
	char addr[31];                                          //��ַ
} DataType;
typedef struct node                                     //������Ͷ���
{
	DataType data;                                           //���������
	struct node *next;                                       //���ָ����
} ListNode;
typedef ListNode *LinkList;
LinkList head;
ListNode *p;
LinkList CreateList(void);
void InsertNode(LinkList head, ListNode *p);//����
ListNode *ListFind(LinkList head);//����
void DelNode(LinkList head);//ɾ��
void PrintList(LinkList head);//���

//β�巨������ͷ����ͨѶ¼�����㷨
LinkList CreateList(void)
{
	LinkList head = (ListNode *)malloc(sizeof(ListNode));         //����ͷ���
	ListNode *p, *rear;
	rear = head;                                                //βָ���ʼָ��ͷ���
	cout << "��������Ҫʹ��ԭ�ȵ�ͨѶ¼�����Լ��½�һ��ͨѶ¼" << endl;
	cout << "����1ѡ��ʹ��ԭ����ͨѶ¼������2ѡ���Լ��½�ͨѶ¼" << endl;
	int my_choice;
	cin >> my_choice;
	if (my_choice == 1)
	{
		//�����ǵ��ļ�������������
		fstream lianxiren_in;
		lianxiren_in.open("D:\\try\\lianxiren.txt", ios::in);
		if (lianxiren_in.fail())
		{
			cout << "�Բ����ļ������ڣ���ֻ��ѡ���½�ͨѶ¼��" << endl;
			return NULL;
		}
		string s1, s2, s3, s4, s5;
		char c1, c2, c3, c4, c5;
		while (lianxiren_in.peek() != EOF)
		{
			p = (ListNode *)malloc(sizeof(ListNode));                     //���½��
			lianxiren_in >> p->data.num;lianxiren_in.get(c1);
			lianxiren_in >> p->data.name;lianxiren_in.get(c2);
			lianxiren_in >> p->data.sex;lianxiren_in.get(c3);
			lianxiren_in >> p->data.phone;lianxiren_in.get(c4);
			lianxiren_in >> p->data.addr;lianxiren_in.get(c5);
			rear->next = p;                                                 //�½�����ӵ�β���֮��
			rear = p;                                                        //βָ��ָ���½��
		}
		rear->next = NULL;                                                    //�ն˽��ָ���ÿ�
		return head;
	}
	else
	{
		char flag = 'y';                                            //int flag=0; ������־�� 0
		//rear = head;                                                //βָ���ʼָ��ͷ���
		//����һ�����ڱ�����ϵ����Ϣ������ļ�
		fstream inout;
		inout.open("D:\\try\\lianxiren.txt", ios::out | ios::trunc);//��������ǰ������ļ��ڵ���������
		inout.close();

		while (flag == 'y')
		{
			inout.open("D:\\try\\lianxiren.txt", ios::out | ios::app);
			p = (ListNode *)malloc(sizeof(ListNode));                     //���½��
			cout << "\n������ͨѶ��Ա�ı�� ���� �Ա� �绰 ��ַ :" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\n ���:";
			cin >> p->data.num;
			cout << "\n ����:";
			cin >> p->data.name;
			cout << "\n �Ա�:";
			cin >> p->data.sex;
			cout << "\n �绰:";
			cin >> p->data.phone;
			cout << "\n ��ַ:";
			cin >> p->data.addr;
			//��������ϵ����Ϣ������������ǵı����ļ�֮��
			inout << p->data.num << '\t' << p->data.name << '\t' << p->data.sex << '\t' << p->data.phone << '\t' << p->data.addr << '\n';
			inout.close();
			rear->next = p;                                                 //�½�����ӵ�β���֮��
			rear = p;                                                        //βָ��ָ���½��
			cout << "�Ƿ��������?(������y/n):";
			cin >> flag;
		}
		rear->next = NULL;                                                    //�ն˽��ָ���ÿ�
		return head;                                                            //��������ͷָ��
	}
	
}
//��ͨѶ¼�����в�����
void InsertNode(LinkList head, ListNode *p)
{
	ListNode *p1, *p2;
	p1 = head;
	p2 = p1->next;
	while (p2 != NULL && strcmp(p2->data.num, p->data.num)<0)
	{
		p1 = p2;                                         //p1 ָ��շ��ʹ��Ľ��
		p2 = p2->next;                                   //p2 ָ������һ�����
	}
	p1->next = p;                                          //���� p ��ָ��Ľ��
	p->next = p2;                                           //���ӱ���ʣ��Ľ��
	fstream aaa;
	aaa.open("D:\\try\\lianxiren.txt", ios::out | ios::trunc);
	/*
	������һ�������bug��
	�����������ios::app�󣬾ͻᷢ���������۲���ʲô��㣬��ֻ�д�������ʱ�Ľ��Ż�д�룬����������κ��ļ�������䶼����ִ��
	��Ȼ�ˣ�����ʱ������Ĭ���ļ�ĩβ�������룬������������û��ios::appʱҲû�г���
    ����������ǵĴ������
	*/
	ListNode *pp = head->next;
	while (pp != NULL) //����Ϊ��ʱ
	{
	aaa<< pp->data.num << '\t' <<pp->data.name << '\t' <<pp->data.sex << '\t' <<pp->data.phone << '\t' <<pp->data.addr << '\n';
	pp = pp->next;
	}
	aaa.close();
	//���ļ�����������
	/*fstream fileout;
	fileout.open("D:\\try\\lianxiren.txt", ios::out |ios::trunc| ios::app); //ios::trunc����Ϊ������ļ����ڣ�����ա�
	ListNode *pp = head->next;
	/*while (pp != NULL) //����Ϊ��ʱ
	{
		fileout<< pp->data.num << '\t' <<pp->data.name << '\t' <<pp->data.sex << '\t' <<pp->data.phone << '\t' <<pp->data.addr << '\n';
		pp = pp->next;
	}
	fileout << "����" << endl;
	fileout.close();*/
}

//������ͨѶ¼�����в��� 
ListNode *ListFind(LinkList head)
{
	ListNode *p;
	char num[5];
	char name[9];
	char pp;
	cout << "   a. ����Ų�ѯ ";
	cout << "   b. ��������ѯ " << endl;
	cout << " ����������ѡ�� ";
	p = head->next;
	cin >> pp;
	while (pp != 'a' && pp != 'A' && pp != 'b'&& pp != 'B')
	{
		cout << "�Բ����������ѡ�������������������ѡ�� ";cin >> pp;
	}
	if (pp == 'a' || pp == 'A')
	{
		cout << "������ͨѶ��Ա��ţ�";
		cin >> num;
		while (p&&strcmp(p->data.num, num) != 0) p = p->next;
		if ((p == NULL)) p = NULL;                                      //û�в鵽ͨѶ��Ϣ
	}
	else if (pp == 'b' || pp == 'B')
	{
		cout << " ������ͨѶ��Ա������";
		cin >> name;
		while (p&&strcmp(p->data.name, name) != 0) p = p->next;
	}
	return p;
}
//ͨѶ¼�����ϵĽ��ɾ��
void DelNode(LinkList head)
{
	char cho;
	ListNode *p, *q;
	p = ListFind(head);                                          //���ò��Һ���
	if (p == NULL)
	{
		cout << "û�в鵽Ҫɾ����ͨѶ��Ա!";
		return;
	}
	else if (p != NULL)
	{
		cout << "��ѯ�ɹ��� " << endl;
		cout << "ͨѶ��Ա��Ϣ���£� ";
		cout << "-----------------------------------------------" << endl;
		cout << "�� ��:" << p->data.num << endl;
		cout << "�� ��:" << p->data.name << endl;
		cout << "�� ��:" << p->data.sex << endl;
		cout << "�� ��:" << p->data.phone << endl;
		cout << "�� ַ:" << p->data.addr << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "ȷ��Ҫɾ����ͨѶ��Ա��Ϣ����������y/n��:";
		cin >> cho;
		if (cho == 'y' || cho == 'Y')
		{
			q = head;
			while ((q != NULL) && (q->next != p)) q = q->next;
			q->next = p->next;                                                 //ɾ�����
			free(p);                                                    //�ͷű�ɾ���ռ�
			cout << "ɾ���ɹ���\n";
		}
	}
	fstream aaa;
	aaa.open("D:\\try\\lianxiren.txt", ios::out | ios::trunc);
	ListNode *pp = head->next;
	while (pp != NULL) //����Ϊ��ʱ
	{
		aaa << pp->data.num << '\t' << pp->data.name << '\t' << pp->data.sex << '\t' << pp->data.phone << '\t' << pp->data.addr << '\n';
		pp = pp->next;
	}
	aaa.close();
}
//ͨѶ¼������������ 
void PrintList(LinkList head)
{
	ListNode *p;
	p = head->next;
	cout << "��ѯ�ɹ���" << endl;
	cout << " ͨѶ¼�����е�����ͨѶ��Ա��" << endl;
	cout << "-------------------------------------------------- " << endl;
	while (p != NULL)
	{
		cout << "�� ��:" << p->data.num << endl;
		cout << "�� ��:" << p->data.name << endl;
		cout << "�� ��:" << p->data.sex << endl;
		cout << "�� ��:" << p->data.phone << endl;
		cout << "�� ַ:" << p->data.addr << endl;
		cout << "-------------------------------------------------- " << endl;
		p = p->next;                                              //����һ�����
	}
}