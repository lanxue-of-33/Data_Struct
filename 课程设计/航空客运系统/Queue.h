#pragma once
#include<iostream>
using namespace std;
//�洢�油�ͻ���Ϣ�Ķ���(���������еķ�ʽ��ʵ�֣�
//�������ȶ���������ͣ�Ȼ���ٶ��������е�����

typedef struct qnode
{
	//Waiting_Customer *data;//�ͻ���Ϣ
	char name[10];//�ȴ��Ŀͻ�����
	int plane_num;//��Ҫ�Ļ�Ʊ��
	int level;     //��Ҫ�Ļ��յȼ�
	int id;        //�õȴ��ͻ��ı��
	struct qnode *next; //ָ����һ������ָ��
}DataNode; //���ӽ�������
typedef struct
{
	DataNode *front;//ָ����׽��
	DataNode *rear;//ָ���β���
}Waiting_LinkQuNode;

//��ʼ������
void InitQueue(Waiting_LinkQuNode*& q)
{
	q = (Waiting_LinkQuNode*)malloc(sizeof(Waiting_LinkQuNode));
	q->front = q->rear = NULL;
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Waiting_LinkQuNode *q)
{
	return q->rear == NULL;
}
//������
//����һ���½�����ڴ��Ԫ��e����pָ��������
//��ԭ����Ϊ�գ������ӽ����������ָ����p�����򽫽��p���ӵ��������ĩβ���������ӽ���rear��ָ����
void enQueue(Waiting_LinkQuNode*& q, int n)
{
	DataNode *pp1;
	pp1 = (DataNode*)malloc(sizeof(DataNode));//�����ȴ��ͻ���㣨�Լ���������)
											  //�õȴ��ͻ��ı��
	pp1->id = n;
	cout << "������Ҫ�ȴ��Ŀͻ�������" << '\t'; cin >> pp1->name;
	cout << "������Ҫ�ȴ��Ŀͻ������Ʊ�յȼ���" << '\t'; cin >> pp1->level;
	cout << "������Ҫ�ȴ��Ŀͻ������Ʊ������" << '\t'; cin >> pp1->plane_num;
	pp1->next = NULL;
	if (q->rear == NULL)   //������Ϊ�գ����½����Ƕ��׽�����Ƕ�β���
		q->front = q->rear = pp1;
	else
	{
		q->rear->next = pp1; //��pp1���������β������rearָ����
		q->rear = pp1;
	}
	cout << "���������" << endl;
}

//������
//��ԭ���в��գ����׽���dataֵ��ֵ���������ɾ��
//��ԭ����ֻ��һ����㣬���轫���ӽ��������������ΪNULL����ʾ�����Կ�
bool deQueue(Waiting_LinkQuNode*&q)
{
	DataNode *t;
	if (q->rear == NULL)  //��ԭ������Ϊ��
		return false;
	t = q->front; //tָ���׽��
	if (q->front == q->rear)  //ԭ��������ֻ��һ�����ݽ��ʱ
		q->front = q->rear = NULL;
	else                      //�����������������������ϵĽ��ʱ
		q->front = q->front->next;
	//free(t);//�ͷ����������ӵĽ�㣬�ȳ��Բ�д��
	return true;
}