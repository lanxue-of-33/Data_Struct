#pragma once
#include<iostream>
using namespace std;
//存储替补客户信息的队列(采用链队列的方式来实现）
//我们首先定义结点的类型，然后再定义链队列的类型

typedef struct qnode
{
	//Waiting_Customer *data;//客户信息
	char name[10];//等待的客户姓名
	int plane_num;//需要的机票数
	int level;     //需要的机舱等级
	int id;        //该等待客户的编号
	struct qnode *next; //指向下一个结点的指针
}DataNode; //链队结点的类型
typedef struct
{
	DataNode *front;//指向队首结点
	DataNode *rear;//指向队尾结点
}Waiting_LinkQuNode;

//初始化队列
void InitQueue(Waiting_LinkQuNode*& q)
{
	q = (Waiting_LinkQuNode*)malloc(sizeof(Waiting_LinkQuNode));
	q->front = q->rear = NULL;
}
//判断队列是否为空
bool QueueEmpty(Waiting_LinkQuNode *q)
{
	return q->rear == NULL;
}
//进队列
//创建一个新结点用于存放元素e（由p指向它）。
//若原队列为空，则将链队结点的两个域均指向结点p，否则将结点p链接到单链表的末尾，并让链队结点的rear域指向它
void enQueue(Waiting_LinkQuNode*& q, int n)
{
	DataNode *pp1;
	pp1 = (DataNode*)malloc(sizeof(DataNode));//创建等待客户结点（自己输入数据)
											  //该等待客户的编号
	pp1->id = n;
	cout << "请输入要等待的客户姓名：" << '\t'; cin >> pp1->name;
	cout << "请输入要等待的客户所需机票舱等级：" << '\t'; cin >> pp1->level;
	cout << "请输入要等待的客户所需机票数量：" << '\t'; cin >> pp1->plane_num;
	pp1->next = NULL;
	if (q->rear == NULL)   //若链队为空，则新结点既是队首结点又是队尾结点
		q->front = q->rear = pp1;
	else
	{
		q->rear->next = pp1; //将pp1结点链到队尾，并将rear指向它
		q->rear = pp1;
	}
	cout << "请输入测试" << endl;
}

//出队列
//若原队列不空，则将首结点的data值域赋值给额，并将其删除
//若原队列只有一个结点，则需将链队结点的两个域均设置为NULL，表示队列以空
bool deQueue(Waiting_LinkQuNode*&q)
{
	DataNode *t;
	if (q->rear == NULL)  //若原来队列为空
		return false;
	t = q->front; //t指向首结点
	if (q->front == q->rear)  //原来队列中只有一个数据结点时
		q->front = q->rear = NULL;
	else                      //若队列中有两个或两个以上的结点时
		q->front = q->front->next;
	//free(t);//释放我们所出队的结点，先尝试不写吧
	return true;
}