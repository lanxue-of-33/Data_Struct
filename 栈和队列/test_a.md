	#include<iostream> 
	using namespace std;
	typedef char ElemType;
	//ʹ����ջʱ����ȡ��㶼�Ƕ��׽����в���������ջ�Ƚ������ԭ��
	typedef struct linknode
	{
	ElemType data; //������
	struct linknode*next; //ָ����
	}LinkStNode; //��ջ�������
	//��ʼ��ջ
	void InitStack(LinkStNode *&s)
	{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;  //���㷨��ʱ�临�Ӷ���O��1��
	}
	//����ջ
	void DestoryStack(LinkStNode*&s)
	{
	LinkStNode*pre = s, *p = s->next;//preָ��ָ��ͷ��㣬pָ���׽ڵ�
	while (p != NULL) //ѭ����pΪ��
	{
		free(pre); //�ͷ�pre���
		pre = p;   //pre��pָ��ͬʱ����
		p = pre->next;
	}
	free(pre); //��ʱpreָ��β��㣬�ͷ���ռ�
	cout << "ջ�ѱ����٣�" << endl;
	}
	//�ж�ջ�Ƿ�Ϊ��
	bool StackEmpty(LinkStNode *s)
	{
	return s->next == NULL;
	}
	//��ջ
	void Push(LinkStNode*&s, ElemType e)
	{
	LinkStNode *p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode)); //�½����p
	p->data = e;
	p->next = s->next;  //ͷ�巨����p��������Ϊ�׽��
	s->next = p;
	}
	//��ջ
	bool Pop(LinkStNode*&s, ElemType &e)
	{
	LinkStNode *p;
	if (s->next == NULL) //ջΪ��ʱ����false
		return false;
	p = s->next;      //pָ���׽��
	e = p->data;
	s->next = p->next; //ɾ���׽��
	free(p); //�ͷű�ɾ���Ľ��p�Ĵ洢�ռ�
	return true;
	}
	//ȡջ��Ԫ��
	bool GetTop(LinkStNode*s, ElemType &e)
	{
	if (s->next == NULL)
		return false;
	e = s->next->data; //��ȡ�׽���ֵ
	return true;
	}
	void main()
	{
	//(1)��ʼ��ջs
	LinkStNode* s;
	InitStack(s);
	//(2)�ж�ջ�Ƿ�Ϊ��
	if (StackEmpty(s))
		cout << "ջΪ��" << endl;
	else
		cout << "ջ��Ϊ��" << endl;
	//(3)���ν�ջԪ��a,b,c,d,e,
	char tt[5] = { 'a','b','c','d','e' };
	for (int i = 0; i < 5; i++)
	{
		Push(s, tt[i]);
	}
	//(4)�ж�ջ�Ƿ�Ϊ��
	if (StackEmpty(s))
		cout << "ջΪ��" << endl;
	else
		cout << "ջ��Ϊ��" << endl;
	//��5�������ջ����
	char e;
	for (int i = 0; i < 5; i++)
	{
		Pop(s, e);
		cout << e << endl;
	}
	//(6)�ж�ջ�Ƿ�Ϊ��
	if (StackEmpty(s))
		cout << "ջΪ��" << endl;
	else
		cout << "ջ��Ϊ��" << endl;
	//(7)�ͷ�ջ
	DestoryStack(s);
	system("pause");
	}
	