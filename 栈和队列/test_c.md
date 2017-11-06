### 这是一个顺序栈
	#include<iostream>
	using namespace std;
	typedef char ElemType;
	#define Maxsize 100
	
	//栈空的条件：s->top=-1
	//栈满的条件：s->top=Maxsize-1(data数组的最大下标)
	//元素e的进栈操作：先将栈顶指针top值加一，然后将元素e放在栈顶指针处
	//元素出栈操作：先将栈顶指针top处的元素取出放在e中，然后将top的值减一
	
	typedef struct
	{
	ElemType data[Maxsize];
	int top;
	}SqStack;
	
	//初始化栈
	void InitStack(SqStack*&s)
	{
	s = (SqStack*)malloc(sizeof(SqStack)); //分配一个顺序栈空间，首地址存放在s中
	s->top = -1;
	}
	
	//销毁栈
	void DestroyStack(SqStack*&s)
	{
	free(s);
	cout << "释放栈成功"<<endl;
	}
	
	//判断栈是否为空
	bool StackEmpty(SqStack*s)
	{
	return (s->top == -1); //为空时返回true
	}
	
	//进栈
	bool Push(SqStack*&s, ElemType e)
	{
	if (s->top == Maxsize - 1)//栈满，返回false
		return false;
	s->top++;            //栈顶指针加一
	s->data[s->top] = e;//元素e放在栈顶指针处
	return true;
	}
	
	//出栈
	bool Pop(SqStack*&s, ElemType &e)
	{
	if (s->top == -1)//栈为空（即栈下溢出）时，返回false
		return false;
	e = s->data[s->top];//取栈顶元素
	s->top--; //栈顶指针减一
	return true;
	}
	
	//取栈顶元素
	bool GetTop(SqStack*s,ElemType &e)
	{
	if (s->top == -1) //栈为空（即栈下溢出）时，返回false
		return false;
	e = s->data[s->top];//去栈顶元素
	return true;
	}
	
	void main()
	{
	//(1)初始化栈s
	SqStack* s;
	InitStack(s);
	//(2)判断栈是否为空
	if (StackEmpty(s))
		cout << "栈为空" << endl;
	else
		cout << "栈不为空" << endl;
	//(3)依次进栈元素a,b,c,d,e,
	char tt[5] = { 'a','b','c','d','e' };
	for (int i = 0; i < 5; i++)
	{
		Push(s, tt[i]);
	}
	//(4)判断栈是否为空
	if (StackEmpty(s))
		cout << "栈为空" << endl;
	else
		cout << "栈不为空" << endl;
	//（5）输出出栈序列
	char e;
	for (int i = 0; i < 5; i++)
	{
		Pop(s, e);
		cout << e << endl;
	}
	//(6)判断栈是否为空
	if (StackEmpty(s))
		cout << "栈为空" << endl;
	else
		cout << "栈不为空" << endl;
	//(7)释放栈
	DestroyStack(s);
	system("pause");
	}