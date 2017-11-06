### ����һ��˳��ջ
	#include<iostream>
	using namespace std;
	typedef char ElemType;
	#define Maxsize 100
	
	//ջ�յ�������s->top=-1
	//ջ����������s->top=Maxsize-1(data���������±�)
	//Ԫ��e�Ľ�ջ�������Ƚ�ջ��ָ��topֵ��һ��Ȼ��Ԫ��e����ջ��ָ�봦
	//Ԫ�س�ջ�������Ƚ�ջ��ָ��top����Ԫ��ȡ������e�У�Ȼ��top��ֵ��һ
	
	typedef struct
	{
	ElemType data[Maxsize];
	int top;
	}SqStack;
	
	//��ʼ��ջ
	void InitStack(SqStack*&s)
	{
	s = (SqStack*)malloc(sizeof(SqStack)); //����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;
	}
	
	//����ջ
	void DestroyStack(SqStack*&s)
	{
	free(s);
	cout << "�ͷ�ջ�ɹ�"<<endl;
	}
	
	//�ж�ջ�Ƿ�Ϊ��
	bool StackEmpty(SqStack*s)
	{
	return (s->top == -1); //Ϊ��ʱ����true
	}
	
	//��ջ
	bool Push(SqStack*&s, ElemType e)
	{
	if (s->top == Maxsize - 1)//ջ��������false
		return false;
	s->top++;            //ջ��ָ���һ
	s->data[s->top] = e;//Ԫ��e����ջ��ָ�봦
	return true;
	}
	
	//��ջ
	bool Pop(SqStack*&s, ElemType &e)
	{
	if (s->top == -1)//ջΪ�գ���ջ�������ʱ������false
		return false;
	e = s->data[s->top];//ȡջ��Ԫ��
	s->top--; //ջ��ָ���һ
	return true;
	}
	
	//ȡջ��Ԫ��
	bool GetTop(SqStack*s,ElemType &e)
	{
	if (s->top == -1) //ջΪ�գ���ջ�������ʱ������false
		return false;
	e = s->data[s->top];//ȥջ��Ԫ��
	return true;
	}
	
	void main()
	{
	//(1)��ʼ��ջs
	SqStack* s;
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
	DestroyStack(s);
	system("pause");
	}