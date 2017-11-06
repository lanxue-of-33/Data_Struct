### ����һ��˳��ѭ������
	#include<iostream>
	using namespace std;
	typedef char ElemType;
	#define Maxsize 100
	
	typedef struct
	{
	ElemType data[Maxsize];
	int front, rear; //��ͷ�Ͷ�βָ��
	}SqQuene;
	
	//��ʼ������
	void InitQuene(SqQuene *&q)
	{
	q = (SqQuene*)malloc(sizeof(SqQuene));
	q->front = q->rear = 0; //����һ���ն���q����front��rearָ������óɳ�ʼ״̬��0ֵ
	}
	
	//���ٶ���
	void DestoryQuene(SqQuene*&q)
	{
	free(q);
	cout << "���ٶ��гɹ�" << endl;
	}
	
	//�ж϶����Ƿ�Ϊ��
	bool QueneEmpty(SqQuene*q)
	{
	return (q->front == q->rear);  //ͷָ���βָ�����ʱ�����ζ���Ϊ��
	}
	
	//������,��βָ��rear������Ԫ��
	bool enQuene(SqQuene*&q, ElemType e)
	{
	if ((q->rear + 1) % Maxsize == q->front)//βָ���һ����ͷָ��ʱ�����ζ�������
		return false;
	q->rear = (q->rear+1) % Maxsize;
	q->data[q->rear] = e;
	return true;
	}
	
	//�����У���ͷָ��front��ɾ��Ԫ��
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
	//(1)��ʼ������q
	InitQuene(q);
	//(2)�ж϶����Ƿ�ǿ�
	if (QueneEmpty(q))
		cout << "����Ϊ��" << endl;
	else
		cout << "���в�Ϊ��" << endl;
	//(3�����ν���Ԫ��a��b��c
	char tt[3] = { 'a','b','c' };
	for (int i = 0; i < 3; i++)
	{
		enQuene(q, tt[i]);
	}
	//(4������һ��Ԫ�أ������Ԫ��
	char e;
	deQuene(q, e);
	cout <<"���ǳ��ӵ�һ��Ԫ�أ�"<< e << endl;
	//(5�����ν���Ԫ��d��e��f
	char ttt[3] = { 'd','e','f' };
	for (int i = 0; i < 3; i++)
	{
		enQuene(q, ttt[i]);
	}
	//(6�������������
	for (int i = 0; i < 5; i++)
	{
		deQuene(q, e);
		cout << e << endl;
	}
	//(7���ͷŶ���
	DestoryQuene(q);
	system("pause");
	}