	#include<iostream> 
	using namespace std;
	typedef char ElemType;
	//使用链栈时，存取结点都是对首结点进行操作（符合栈先进后出的原则）
	typedef struct linknode
	{
	ElemType data; //数据域
	struct linknode*next; //指针域
	}LinkStNode; //链栈结点类型
	//初始化栈
	void InitStack(LinkStNode *&s)
	{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;  //本算法的时间复杂度是O（1）
	}
	//销毁栈
	void DestoryStack(LinkStNode*&s)
	{
	LinkStNode*pre = s, *p = s->next;//pre指针指向头结点，p指向首节点
	while (p != NULL) //循环到p为空
	{
		free(pre); //释放pre结点
		pre = p;   //pre和p指针同时后移
		p = pre->next;
	}
	free(pre); //此时pre指向尾结点，释放其空间
	cout << "栈已被销毁！" << endl;
	}
	//判断栈是否为空
	bool StackEmpty(LinkStNode *s)
	{
	return s->next == NULL;
	}
	//进栈
	void Push(LinkStNode*&s, ElemType e)
	{
	LinkStNode *p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode)); //新建结点p
	p->data = e;
	p->next = s->next;  //头插法，将p结点插入作为首结点
	s->next = p;
	}
	//出栈
	bool Pop(LinkStNode*&s, ElemType &e)
	{
	LinkStNode *p;
	if (s->next == NULL) //栈为空时返回false
		return false;
	p = s->next;      //p指向首结点
	e = p->data;
	s->next = p->next; //删除首结点
	free(p); //释放被删除的结点p的存储空间
	return true;
	}
	//取栈顶元素
	bool GetTop(LinkStNode*s, ElemType &e)
	{
	if (s->next == NULL)
		return false;
	e = s->next->data; //提取首结点的值
	return true;
	}
	void main()
	{
	//(1)初始化栈s
	LinkStNode* s;
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
	DestoryStack(s);
	system("pause");
	}
	