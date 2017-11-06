### 这是一个顺序循环队列
	#include<iostream>
	using namespace std;
	typedef char ElemType;
	#define Maxsize 100
	
	typedef struct
	{
	ElemType data[Maxsize];
	int front, rear; //队头和队尾指针
	}SqQuene;
	
	//初始化队列
	void InitQuene(SqQuene *&q)
	{
	q = (SqQuene*)malloc(sizeof(SqQuene));
	q->front = q->rear = 0; //构造一个空队列q，将front和rear指针均设置成初始状态即0值
	}
	
	//销毁队列
	void DestoryQuene(SqQuene*&q)
	{
	free(q);
	cout << "销毁队列成功" << endl;
	}
	
	//判断队列是否为空
	bool QueneEmpty(SqQuene*q)
	{
	return (q->front == q->rear);  //头指针和尾指针相等时代表环形队列为空
	}
	
	//进队列,从尾指针rear处插入元素
	bool enQuene(SqQuene*&q, ElemType e)
	{
	if ((q->rear + 1) % Maxsize == q->front)//尾指针加一等于头指针时代表环形队列已满
		return false;
	q->rear = (q->rear+1) % Maxsize;
	q->data[q->rear] = e;
	return true;
	}
	
	//出队列，从头指针front处删除元素
	bool deQuene(SqQuene*&q, ElemType &e)
	{
	if (q->front == q->rear)
		return false;
	q->front = (q->front + 1) % Maxsize;
	e = q->data[q->front];
	return true;
	}
	
	void main()
	{
	SqQuene *q;
	//(1)初始化队列q
	InitQuene(q);
	//(2)判断队列是否非空
	if (QueneEmpty(q))
		cout << "队列为空" << endl;
	else
		cout << "队列不为空" << endl;
	//(3）依次进队元素a，b，c
	char tt[3] = { 'a','b','c' };
	for (int i = 0; i < 3; i++)
	{
		enQuene(q, tt[i]);
	}
	//(4）出队一个元素，输出该元素
	char e;
	deQuene(q, e);
	cout <<"这是出队的一个元素："<< e << endl;
	//(5）依次进队元素d，e，f
	char ttt[3] = { 'd','e','f' };
	for (int i = 0; i < 3; i++)
	{
		enQuene(q, ttt[i]);
	}
	//(6）输出出队序列
	for (int i = 0; i < 5; i++)
	{
		deQuene(q, e);
		cout << e << endl;
	}
	//(7）释放队列
	DestoryQuene(q);
	system("pause");
	}