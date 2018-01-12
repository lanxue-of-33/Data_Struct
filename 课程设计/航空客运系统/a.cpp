#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
//#include"Queue.h"
using namespace std;

//#include"Queue.h"

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


//#include"test.h"

//飞机上各等级所拥有的票数（默认只有一二三等舱）
typedef struct level
{
	int first;//一等舱的数量
	int Remaining_first;//剩余的一等舱的数量
	int second;//二等舱的数量
	int Remaining_second;//剩余的二等舱数量
	int third;//三等舱的数量
	int Remaining_third;//剩余的三等舱数量
	int all; //加起来所有的订票数
	int Remaining_all;//加起来的所有剩余票数
}level;
//已订票的乘客信息
typedef struct booking
{
	char Name[15];		//乘客姓名
	char number[10];	//乘客所乘飞机航班号
	char end[15];		//乘客终点站
	level booked_level; //乘客所定的飞机票的舱位
	int id;             //每位已订票的乘客都有自己的订单编号
	struct	booking *next;//下一个乘客
}Booking_Customer;

//飞机航班的具体信息
typedef struct
{
	char number[10];	//航班号
	char planenum[10];	//飞机号
	char end[10];		//终点站
	char date[10];		//飞行日期
	level flight_level;	//成员定额（即该飞机一次能容纳多少人）
	int wait_count;			//排队等候的人数
	int book_count;          //已订票的乘客数量
	Booking_Customer *head;	//链接已订票客户
	Waiting_LinkQuNode *Q;		//链接候补客户队列
}flight_info;
//这个系统之内所有航班的集合（也可以理解为我们默认的这一条航线上的所有航班信息）
typedef struct all_flight
{
	flight_info data;
	all_flight *next;
}all_flight;


//#include"Insert.h"

//航班信息录入
void Insert(all_flight*& Begin)
{
	cout << endl << "----------------欢迎来到航班信息录入界面----------------" << endl << endl;
	all_flight *s, *p; //p指针始终指向链表的末尾
	Begin = (all_flight*)malloc(sizeof(all_flight));
	p = Begin;
	cout << "请输入你要输入的航班数："; int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		s = (all_flight*)malloc(sizeof(all_flight)); //航班结点
		cout << "请输入航班号：" << endl;
		cin >> s->data.number; //这里指向航班号时，不能用“->”，只能用“.”,因为这不是指针
		cout << "请输入飞机号：" << endl;
		cin >> s->data.planenum;
		cout << "请输入终点站：" << endl;
		cin >> s->data.end;
		cout << "请输入飞行日期：" << endl;
		cin >> s->data.date;
		cout << "请输入成员定额：" << endl;
		cout << "请输入该航班一等舱的数量" << endl; cin >> s->data.flight_level.first;
		cout << "请输入该航班二等舱的数量" << endl; cin >> s->data.flight_level.second;
		cout << "请输入该航班三等舱的数量" << endl; cin >> s->data.flight_level.third;
		s->data.flight_level.all = s->data.flight_level.first + s->data.flight_level.second + s->data.flight_level.third;
		s->data.flight_level.Remaining_first = s->data.flight_level.first;
		s->data.flight_level.Remaining_second = s->data.flight_level.second;
		s->data.flight_level.Remaining_third = s->data.flight_level.third;
		s->data.flight_level.Remaining_all = s->data.flight_level.all;
		cout << "该航班成员定额（机票总数量）为：" << s->data.flight_level.all << endl;

		cout << "接下来输入已经订票的乘客信息" << endl;
		Booking_Customer *pp, *p1;
		s->data.book_count = 0;
		//下面是为航班结点中的已订单乘客链表分配存储空间
		s->data.head = (Booking_Customer*)malloc(sizeof(Booking_Customer));//当没有在这里分配存储空间时会出错
		pp = s->data.head;//pp是用来指向该乘客信息链表的末尾的
		cout << "按下1开始输入已经订票的乘客信息" << endl;
		int a; cin >> a;
		if (a == 1)
		{
			while (a == 1)
			{
				s->data.book_count++; //当前航班的已经订票的乘客数量
				p1 = (Booking_Customer*)malloc(sizeof(Booking_Customer));//新建已订票乘客结点
				cout << "请输入第" << s->data.book_count << "位乘客的信息" << endl;
				cout << "其订单编号为：" << '\t' << s->data.book_count << endl; p1->id = s->data.book_count;
				cout << "请输入其姓名：" << '\t';   cin >> p1->Name; cout << endl;
				cout << "请输入航班号（" << s->data.number << ")进行确认："; cin >> p1->number; cout << endl;
				cout << "请输入抵达城市（" << s->data.end << "）进行确认："; cin >> p1->end; cout << endl;
				cout << "请输入订票的舱位等级：" << '\t'; int aa; cin >> aa; cout << endl;
				//将乘客的订票数首先初始化为0
				p1->booked_level.first = p1->booked_level.second = p1->booked_level.third = 0;
				cout << "请输入其订票数：" << '\t';  int bb; cin >> bb; cout << endl;
				switch (aa)
				{
				case 1:p1->booked_level.first = bb;
					p1->booked_level.all = p1->booked_level.first;
					s->data.flight_level.Remaining_first = s->data.flight_level.first - p1->booked_level.first;//该航班所剩下的一等舱的票数
					s->data.flight_level.Remaining_all = s->data.flight_level.Remaining_all - p1->booked_level.first;//该航班所剩下的所有票数
					break;
				case 2:p1->booked_level.second = bb;
					p1->booked_level.all = p1->booked_level.second;
					s->data.flight_level.Remaining_second = s->data.flight_level.second - p1->booked_level.second;//该航班所剩下的二等舱的票数
					s->data.flight_level.Remaining_all = s->data.flight_level.Remaining_all - p1->booked_level.second;//该航班所剩下的所有票数
					break;
				case 3:p1->booked_level.third = bb;
					p1->booked_level.all = p1->booked_level.third;
					s->data.flight_level.Remaining_third = s->data.flight_level.third - p1->booked_level.third;//该航班所剩下的三等舱的票数
					s->data.flight_level.Remaining_all = s->data.flight_level.Remaining_all - p1->booked_level.third;//该航班所剩下的所有票数
				default:
					break;
				}
				cout << "该乘客订了" << p1->booked_level.all << "张票！" << endl;
				cout << "输入1继续输入乘客信息，输入2退出输入乘客信息";
				//采用的是尾插法将新建的乘客信息结点插入到已订票乘客链表的末尾
				pp->next = p1;
				pp = p1;
				p1 = NULL;
				cin >> a;
			}
			pp->next = NULL;
			pp = NULL;
		}
		else
		{
			s->data.head->next = NULL;
			cout << "该航班暂时没有已订票的乘客。" << endl;
		}
		cout << endl;
		//free(pp);

		//接下来该输入替补客户的信息
		InitQueue(s->data.Q); //初始化等待替补客户的队列
							  //Waiting_LinkQuNode *q;
		s->data.wait_count = 0;
		int aaa; int mmm = 0;
		cout << "是否有等待替补的乘客（1代表有，2代表没有）"; cin >> aaa;
		if (aaa == 1)
		{
			cout << "接下来录入等待替补的乘客信息：" << endl;
			while (aaa == 1)
			{
				s->data.wait_count++; mmm++;
				cout << "该客户为队列中的第" << s->data.wait_count << "位乘客" << endl;
				enQueue(s->data.Q, s->data.wait_count);
				cout << "输入1代表继续输入等待乘客的信息：" << endl;
				cin >> aaa;
			}
			cout << "共循环了" << mmm << "次" << endl << endl;
		}
		else
		{
			cout << "该航班现在没有等待替补的乘客。" << endl << endl;
		}


		//采用尾插法插入结点（输入航班信息）
		p->next = s;
		p = s;
	}
	p->next = NULL; //将尾结点的next值设置为空

					//输入完毕后使用清屏函数进行下一步
	cout << endl << endl;
	/*cout << "输入e代表清屏：" << endl;
	char e;cin >> e;
	if(e=='e')
	system("cls");*/
}

//#include"Search.h"

void Search(all_flight*& Begin)
{
	cout << "-------------------欢迎来到航班信息查询界面--------------------" << endl << endl;
	all_flight *p, *q;
	// = Begin->next;q = Begin->next;
	char flag = 'e';
	int choice;
	char hangbanhao[10];
	char city[10];
	while (flag == 'e')
	{
		p = Begin->next; q = Begin->next;
		cout << "按航班号查询按1，按2是按起飞抵达城市查询飞机航班情况" << endl;
		cout << "请输入查询方式" << endl; cin >> choice;
		switch (choice)
		{
		case 1:cout << "请输入你要查询的航班号："; cin >> hangbanhao;
			while (p != NULL)
			{
				if (strcmp(p->data.number, hangbanhao) == 0)
				{
					cout << "该航班的起飞时间为：" << '\t' << p->data.date << endl;
					cout << "该航班的抵达城市为：" << '\t' << p->data.end << endl;
					cout << "该航班已有乘客数：" << '\t' << p->data.book_count << endl;
					cout << "该航班等候替补乘客数：" << '\t' << p->data.wait_count << endl;
					cout << "该航班的余票数量如下：" << endl;
					cout << "剩余一等舱的票数：" << '\t' << p->data.flight_level.Remaining_first << endl;
					cout << "剩余二等舱的票数：" << '\t' << p->data.flight_level.Remaining_second << endl;
					cout << "剩余三等舱的票数：" << '\t' << p->data.flight_level.Remaining_third << endl;
					cout << "总剩票数为： " << '\t' << p->data.flight_level.Remaining_all << endl;
					//cout << "按1查看一定票的乘客具体信息，按2不查看";
					p = p->next;
				}
				else
				{
					p = p->next;
				}
			} break;
		case 2:cout << "请输入你要抵达的城市:"; cin >> city;
			while (q != NULL)
			{
				if (strcmp(q->data.end, city) == 0)//判断两个字符串是否相等
				{
					cout << "到达该城市的航班号为:" << '\t' << q->data.number << endl;
					cout << "该航班的起飞时间为:" << '\t' << q->data.date << endl;
					cout << "该航班的飞机号为：" << '\t' << q->data.planenum << endl;
					cout << "该航班已有乘客数：" << '\t' << q->data.book_count << endl;
					cout << "该航班等候替补乘客数：" << '\t' << q->data.wait_count << endl;
					cout << "该航班的余票数量如下：" << endl;
					cout << "剩余一等舱的票数：" << '\t' << q->data.flight_level.Remaining_first << endl;
					cout << "剩余二等舱的票数：" << '\t' << q->data.flight_level.Remaining_second << endl;
					cout << "剩余三等舱的票数：" << '\t' << q->data.flight_level.Remaining_third << endl;
					cout << "总剩票数为： " << '\t' << q->data.flight_level.Remaining_all << endl;
					q = q->next;
				}
				else
					q = q->next;
			}
		default:
			break;
		}
		cout << "是否继续查询（按‘e'继续查询，按’a‘退出查询）:  "; cin >> flag;
	}
	//查询完毕后进行下一步
	//system("cls");
}

//#include"Booking.h"

void Bookint(all_flight*&Begin)
{
	cout << endl << "-------------------欢迎来到订单界面-------------------" << endl << endl;
	all_flight *p = Begin;
	all_flight *pppp = Begin;//指针pppp指向航班链表的第一个结点内容，这是用来推荐航班用的
	Booking_Customer*rear;
	//Booking_Customer *rear1;//rear指针指向客户链表的末尾,rear1是当我们推荐航班时，用来指向当前航班客户端链表的末尾
	int flag1 = 0;//用来判断是否有符合乘客要求的航班号
	char number[10];//订票的航班号
	int level;      //请输入你要乘坐的舱位
	int booking_num;//需要订票的数量
	cout << "请输入你要乘坐的航班号：" << '\t'; cin >> number;
	cout << "请输入你要乘坐的舱位：" << '\t'; cin >> level;
	cout << "请输入你要预定的票数：" << '\t'; cin >> booking_num;
	while (p->next != NULL)
	{
		p = p->next; //p代表的就是当前航班
		if (strcmp(p->data.number, number) == 0)
		{
			flag1 = 1;//表示有符合乘客要求的航班号
			switch (level)
			{
			case 1:if (booking_num > p->data.flight_level.Remaining_first)
			{
				cout << "对不起，该舱位的剩余票数少于你要预定的票数！" << endl;
				cout << "请问是否需要进入等待替补的客户名单（按1表示进入，按2进行航班推荐,按3离开订单界面）" << '\t';
				int tui; cin >> tui;
				switch (tui)
				{
				case 1:p->data.wait_count++;
					cout << "你是等待队列中的第" << p->data.wait_count << "位乘客" << endl;
					enQueue(p->data.Q, p->data.wait_count);
					cout << "操作成功，有票时我们将为你优先出票！！！" << endl;
					break;
				case 2:	while (pppp->next != NULL)
				{
					pppp = pppp->next;
					if (pppp->data.number != p->data.number)
					{
						switch (level)
						{
						case 1:if (pppp->data.flight_level.Remaining_first < booking_num);
							if (pppp->data.flight_level.Remaining_first > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer *rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市(" << pppp->data.end << ")" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.first = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_first = pppp->data.flight_level.Remaining_first - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);

									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						case 2:if (pppp->data.flight_level.Remaining_second < booking_num);
							if (pppp->data.flight_level.Remaining_second > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer*	rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市：" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.second = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_second = pppp->data.flight_level.Remaining_second - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						case 3:if (pppp->data.flight_level.Remaining_third < booking_num);
							if (pppp->data.flight_level.Remaining_third > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer* rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市：" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.third = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_third = pppp->data.flight_level.Remaining_third - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						}
					}
				}
				default:
					cout << "欢迎你下次再来订票！！！" << endl;
					break;
				}
			}
				   else
				   {
					   rear = p->data.head;//rear指针指向当前航班客户链表的尾结点
					   cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
					   //接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
					   Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
					   while (rear->next != NULL)
					   {
						   rear = rear->next;
					   }
					   cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
					   cout << "请输入你要抵达的城市(" << p->data.end << ")" << '\t'; cin >> book->end;
					   cout << "请确认输入你的航班号进行确认" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
					   cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
					   //该乘客的订单编号
					   p->data.book_count++;
					   book->id = p->data.book_count;
					   //将乘客的订票数首先初始化为0
					   book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
					   cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
					   switch (level)
					   {
					   case 1:book->booked_level.first = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - booking_num;//该航班一等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
						   break;
					   case 2:book->booked_level.second = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - booking_num;//该航班二等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
						   break;
					   case 3:book->booked_level.third = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - booking_num;//该航班三等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
					   default:
						   break;
					   }
					   book->next = NULL;
					   //尾结点链接
					   rear->next = book;
					   rear = book;
					   //下面的三行代码是为了释放掉rear指针，为再次调用作准备的
					   rear = NULL; free(rear);
					   //book->next = NULL;
					   //rear = book->next;
					   //free(rear);
				   }
				   break;
			case 2:if (booking_num > p->data.flight_level.Remaining_second)
			{
				cout << "对不起，该舱位的剩余票数少于你要预定的票数！" << endl;
				cout << "请问是否需要进入等待替补的客户名单（按1表示进入，按2进行航班推荐,按3离开订单界面）" << '\t';
				int tui; cin >> tui;
				switch (tui)
				{
				case 1:p->data.wait_count++;
					cout << "你是等待队列中的第" << p->data.wait_count << "位乘客" << endl;
					enQueue(p->data.Q, p->data.wait_count);
					cout << "操作成功，有票时我们将为你优先出票！！！" << endl;
					break;
				case 2:	while (pppp->next != NULL)
				{
					pppp = pppp->next;
					if (pppp->data.number != p->data.number)
					{
						switch (level)
						{
						case 1:if (pppp->data.flight_level.Remaining_first < booking_num);
							if (pppp->data.flight_level.Remaining_first > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer *rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市(" << pppp->data.end << ")" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.first = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_first = pppp->data.flight_level.Remaining_first - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);

									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						case 2:if (pppp->data.flight_level.Remaining_second < booking_num);
							if (pppp->data.flight_level.Remaining_second > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer*	rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市：" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.second = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_second = pppp->data.flight_level.Remaining_second - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						case 3:if (pppp->data.flight_level.Remaining_third < booking_num);
							if (pppp->data.flight_level.Remaining_third > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer* rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市：" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.third = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_third = pppp->data.flight_level.Remaining_third - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						}
					}
				}
				default:
					cout << "欢迎你下次再来订票！！！" << endl;
					break;
				}
			}
				   else
				   {
					   rear = p->data.head;//rear指针指向客户链表的尾结点
					   cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
					   //接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
					   Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
					   while (rear->next != NULL)
					   {
						   rear = rear->next;
					   }
					   cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
					   cout << "请输入你要抵达的城市(" << p->data.end << ")" << '\t'; cin >> book->end;
					   cout << "请确认输入你的航班号进行确认" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
					   cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
					   //将乘客的订票数首先初始化为0
					   book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
					   cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
					   //该乘客的订单编号
					   p->data.book_count++;
					   book->id = p->data.book_count;
					   switch (level)
					   {
					   case 1:book->booked_level.first = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - booking_num;//该航班一等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
						   break;
					   case 2:book->booked_level.second = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - booking_num;//该航班二等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
						   break;
					   case 3:book->booked_level.third = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - booking_num;//该航班三等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
					   default:
						   break;
					   }
					   book->next = NULL;
					   //尾结点链接
					   rear->next = book;
					   rear = book;
					   //下面的三行代码是为了释放掉rear指针，为再次调用作准备的
					   rear = NULL; free(rear);
					   // book->next = NULL;
					   //rear = book->next;
					   //free(rear);
				   }
				   break;
			case 3:if (booking_num > p->data.flight_level.Remaining_third)
			{
				cout << "对不起，该舱位的剩余票数少于你要预定的票数！" << endl;
				cout << "请问是否需要进入等待替补的客户名单（按1表示进入，按2进行航班推荐,按3离开订单界面）" << '\t';
				int tui; cin >> tui;
				switch (tui)
				{
				case 1:p->data.wait_count++;
					cout << "你是等待队列中的第" << p->data.wait_count << "位乘客" << endl;
					enQueue(p->data.Q, p->data.wait_count);
					cout << "操作成功，有票时我们将为你优先出票！！！" << endl;
					break;
				case 2:	while (pppp->next != NULL)
				{
					pppp = pppp->next;
					if (pppp->data.number != p->data.number)
					{
						switch (level)
						{
						case 1:if (pppp->data.flight_level.Remaining_first < booking_num);
							if (pppp->data.flight_level.Remaining_first > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer *rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市(" << pppp->data.end << ")" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.first = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_first = pppp->data.flight_level.Remaining_first - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);

									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						case 2:if (pppp->data.flight_level.Remaining_second < booking_num);
							if (pppp->data.flight_level.Remaining_second > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer*	rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市：" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.second = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_second = pppp->data.flight_level.Remaining_second - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						case 3:if (pppp->data.flight_level.Remaining_third < booking_num);
							if (pppp->data.flight_level.Remaining_third > booking_num)
							{
								cout << "航班号为：" << pppp->data.number << "的航班有符合你要求的票，请问是否订票（按1是，按2否）？：";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//将该乘客加入到我们所查询到的这趟航班之中
									Booking_Customer* rear1 = pppp->data.head;//rear指针指向当前航班客户链表的尾结点
									cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
									//接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
									cout << "请输入你要抵达的城市：" << '\t'; cin >> book->end;
									cout << "请确认输入你的航班号进行确认" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//将乘客的订票数首先初始化为0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "请输入你的票数进行确认" << "(" << pppp->data.number << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.third = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_third = pppp->data.flight_level.Remaining_third - booking_num;//该航班一等舱剩余票数
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
									book->next = NULL;
									//尾结点链接
									rear1->next = book;
									rear1 = book;
									//下面的三行代码是为了释放掉rear指针，为再次调用作准备的
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//加入到我们所推荐的航班的客户列表名单中成功
									cout << "恭喜你：" << book->Name << "你去往 " << book->end << " 的航班 " << book->number << " 订票成功！！！" << endl;
								}
								else
									cout << "很抱歉，该航班没让你满意，请继续浏览我们的信息。" << endl;
							}
							break;
						}
					}
				}
				default:
					cout << "欢迎你下次再来订票！！！" << endl;
					break;
				}
			}
				   else
				   {
					   rear = p->data.head;//rear指针指向客户链表的尾结点
					   cout << "恭喜你，该舱位票数充足，接下来请输入你的信息进行订票！！！" << endl;
					   //接下来，创建一个订单客户结点，将其插入到给航班的订单客户链表之中
					   Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//分配空间
					   while (rear->next != NULL)
					   {
						   rear = rear->next;
					   }
					   cout << "请输入你的姓名：" << '\t'; cin >> book->Name; cout << endl;
					   cout << "请输入你要抵达的城市(" << p->data.end << ")" << '\t'; cin >> book->end;
					   cout << "请确认输入你的航班号进行确认" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
					   cout << "请输入你的舱位进行确认" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
					   //将乘客的订票数首先初始化为0
					   book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
					   cout << "请输入你的票数进行确认" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
					   //该乘客的订单编号
					   p->data.book_count++;
					   book->id = p->data.book_count;
					   switch (level)
					   {
					   case 1:book->booked_level.first = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - booking_num;//该航班一等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
						   break;
					   case 2:book->booked_level.second = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - booking_num;//该航班二等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
						   break;
					   case 3:book->booked_level.third = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - booking_num;//该航班三等舱剩余票数
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//该航班总剩余票数
					   default:
						   break;
					   }
					   book->next = NULL;
					   //尾结点链接
					   rear->next = book;
					   rear = book;
					   //下面的三行代码是为了释放掉rear指针，为再次调用作准备的
					   rear = NULL; free(rear);
					   //book->next = NULL;
					   //rear = book->next;
					   // free(rear);
				   }
				   break;
			default:
				break;
			}
		}
	}
	if (flag1 == 0)
		cout << "很抱歉啦，没有你要坐的航班啦！！！" << endl;
	rear = NULL;
	p = NULL;
	pppp = NULL;
}

//#include"tuipiao.h"

void Tuipiao(all_flight*& Begin)
{
	cout << endl << "------------------欢迎来到退票界面-------------------" << endl << endl;
	all_flight *p = Begin;//p指向的是当前所选中的航班
	Booking_Customer *ppppp;//pppp指针指向的是航班之中已订票的乘客链表
	Booking_Customer *qqqqq;//是为了用来删除退票乘客的结点
	Booking_Customer *ttttt;//这是用来改变退票乘客的订单编号
	Booking_Customer *rear;//用来指向乘客订单的尾部
	int flag1 = 0, flag2 = 0;//flag1代表有无该航班，flag2代表该航班有无该乘客
							 //输入退票者的姓名及航班
	char exit_name[10]; char exit_num[10];
	cout << "请输入你的姓名:" << '\t'; cin >> exit_name; cout << endl;
	cout << "请输入你的航班号：" << '\t'; cin >> exit_num; cout << endl;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->data.number, exit_num) == 0)
		{
			flag1 = 1;
			ppppp = p->data.head;
			qqqqq = p->data.head;
			ttttt = p->data.head;
			while (ppppp->next != NULL)//该航班有已订票的乘客
			{
				qqqqq = ppppp;
				ppppp = ppppp->next;
				if (strcmp(ppppp->Name, exit_name) == 0)//找到了该乘客的话，要将其从已订票乘客链表之中删除
				{
					flag2 = 1;
					cout << ppppp->Name << " : 你所乘坐的 " << p->data.number << " 号航空的 " << ppppp->booked_level.all << " 张票已经退票成功！！！" << endl;
					if (ppppp->booked_level.first != 0)//该乘客退了该航班一等舱的票，则该航班一等舱的剩余票和总剩余票都要增加
					{
						p->data.book_count--;//乘客数量减一
						p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first + ppppp->booked_level.first;
						p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all + ppppp->booked_level.first;
					}
					if (ppppp->booked_level.second != 0)//该乘客退了该航班二等舱的票，则该航班一等舱的剩余票和总剩余票都要增加
					{
						p->data.book_count--;//乘客数量减一
						p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second + ppppp->booked_level.second;
						p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all + ppppp->booked_level.second;
					}
					if (ppppp->booked_level.third != 0)//该乘客退了该航班三等舱的票，则该航班一等舱的剩余票和总剩余票都要增加
					{
						p->data.book_count--;//乘客数量减一
						p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third + ppppp->booked_level.third;
						p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all + ppppp->booked_level.third;
					}
					//这是删除结点操作,删除完后就可以跳出循环了
					if (ppppp->next = NULL)
					{
						qqqqq->next = NULL;//break;
					}
					else
					{
						qqqqq->next = ppppp->next;//break;
					}
					//删除完之后，遍历等待队列，如果有符合条件的，就将其添加到订票乘客列表之中
					if (p->data.wait_count == 0)
					{
						cout << "该航班没有等待替补的人员！！！" << endl;
					}
					else
					{
						switch (p->data.Q->front->level)
						{
						case 1:if (p->data.Q->front->plane_num < p->data.flight_level.Remaining_first)//如果等待客户所需机票数小于当前航班的剩余机票数,是一等舱
						{
							rear = p->data.head;
							//接下来新建一个订票乘客结点，然后将其用尾插法插入到我们已定机票的乘客链表之中
							Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));
							while (rear->next != NULL)
							{
								rear = rear->next;
							}
							//乘客姓名
							//book->Name = p->data.Q->front->name;
							cout << "请输入等待队列中的乘客姓名（" << p->data.Q->front->name << ")确认为其进行订票："; cin >> book->Name; cout << endl;
							cout << "成功为 " << book->Name << " 乘客订票！！！" << endl;
							//乘客所要抵达的城市
							//book->end=p->data.Q->front.
							//该乘客的订单编号
							p->data.book_count++;
							book->id = p->data.book_count;
							//乘客的订票量
							book->booked_level.first = p->data.Q->front->plane_num;
							book->booked_level.all = p->data.Q->front->plane_num;
							p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - p->data.Q->front->plane_num;//该航班一等舱剩余票数
							p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - p->data.Q->front->plane_num;//该航班总剩余票数

							book->next = NULL;
							//尾结点链接
							rear->next = book;
							rear = book;
							//释放指针
							rear = NULL; free(rear);

							//将我们符合条件的乘客出队列,然后将该航班中等待替补人数减一
							deQueue(p->data.Q);
							p->data.wait_count--;
						}
							   else
							   {
								   cout << "所退的票不符合乘客要求，无法自动订票！！" << endl;
							   }
							   break;
						case 2:if (p->data.Q->front->plane_num < p->data.flight_level.Remaining_second)
						{
							rear = p->data.head;
							//接下来新建一个订票乘客结点，然后将其用尾插法插入到我们已定机票的乘客链表之中
							Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));
							while (rear->next != NULL)
							{
								rear = rear->next;
							}
							//乘客姓名
							//book->Name = p->data.Q->front->name;
							cout << "请输入等待队列中的乘客姓名（" << p->data.Q->front->name << ")确认为其进行订票："; cin >> book->Name; cout << endl;
							cout << "成功为 " << book->Name << " 乘客订票！！！" << endl;
							//乘客所要抵达的城市
							//book->end=p->data.Q->front.
							//该乘客的订单编号
							p->data.book_count++;
							book->id = p->data.book_count;
							//乘客的订票量
							book->booked_level.second = p->data.Q->front->plane_num;
							book->booked_level.all = p->data.Q->front->plane_num;
							p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - p->data.Q->front->plane_num;//该航班二等舱剩余票数
							p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - p->data.Q->front->plane_num;//该航班总剩余票数

							book->next = NULL;
							//尾结点链接
							rear->next = book;
							rear = book;
							//释放指针
							rear = NULL; free(rear);

							//将我们符合条件的乘客出队列,然后将该航班中等待替补人数减一
							deQueue(p->data.Q);
							p->data.wait_count--;
						}
							   else
							   {
								   cout << "所退的票不符合乘客要求，无法自动订票！！" << endl;
							   }
							   break;
						case 3:if (p->data.Q->front->plane_num < p->data.flight_level.Remaining_third)
						{
							rear = p->data.head;
							//接下来新建一个订票乘客结点，然后将其用尾插法插入到我们已定机票的乘客链表之中
							Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));
							while (rear->next != NULL)
							{
								rear = rear->next;
							}
							//乘客姓名
							//book->Name = p->data.Q->front->name;
							cout << "请输入等待队列中的乘客姓名（" << p->data.Q->front->name << ")确认为其进行订票："; cin >> book->Name; cout << endl;
							cout << "成功为 " << book->Name << " 乘客订票！！！" << endl;
							//乘客所要抵达的城市
							//book->end=p->data.Q->front.
							//该乘客的订单编号
							p->data.book_count++;
							book->id = p->data.book_count;
							//乘客的订票量
							book->booked_level.third = p->data.flight_level.third;
							book->booked_level.all = p->data.Q->front->plane_num;
							p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - p->data.Q->front->plane_num;//该航班三等舱剩余票数
							p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - p->data.Q->front->plane_num;//该航班总剩余票数

							book->next = NULL;
							//尾结点链接
							rear->next = book;
							rear = book;
							//释放指针
							rear = NULL; free(rear);

							//将我们符合条件的乘客出队列,然后将该航班中等待替补人数减一
							deQueue(p->data.Q);
							p->data.wait_count--;
						}
							   else
							   {
								   cout << "所退的票不符合乘客要求，无法自动订票！！" << endl;
							   }
							   break;
						}
					}
				}
			}
			//改变已订票客户的编号
			int n = 0;
			while (ttttt->next != NULL)
			{
				n++;
				ttttt->id = n;
				ttttt = ttttt->next;
			}
			//释放指针
			ppppp = NULL; free(ppppp);
			qqqqq = NULL; free(qqqqq);
			ttttt = NULL; free(ttttt);
		}
	}
	if (flag1 == 1)
	{
		if (flag2 == 0)
			cout << "很抱歉，该航班已订票乘客中无名为 " << exit_name << " 的乘客！！" << endl;
	}
	else
		cout << "很抱歉，没有你输入的名为 " << exit_num << " 的航班！！" << endl;
}

void main3()
{
	all_flight *Begin; //航班列表开始
	int flagall = 0;
	char e;
	while (1)
	{
		int a_a;
		cout << '\t' << '\t' << "********************功能选择首页*************************" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           1--航班信息录入功能                       **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           2--航班信息查询功能                       **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           3--航班订票功能                           **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           4--航班退票功能                           **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "*********************************************************" << endl;
		cout << '\t' << '\t' << "请输入你要选择的功能" << '\t'; cin >> a_a;
		system("cls");
		switch (a_a)
		{
		case 1:flagall = 1;
			Insert(Begin);
			cout << "按e返回主页面："; cin >> e;
			while (e != 'e')
			{
				cout << "按e返回主页面：";
				cin >> e;
			}
			system("cls");
			break;
		case 2:
			if (flagall == 0)
			{
				cout << "还未录入航班信息，请先进行信息录入！！！" << endl;
			}
			else
				Search(Begin);
			cout << "按e返回主页面："; cin >> e;
			while (e != 'e')
			{
				cout << "按e返回主页面：";
				cin >> e;
			}
			system("cls");
			break;
		case 3:
			if (flagall == 0)
			{
				cout << "还未录入航班信息，请先进行信息录入！！！" << endl;
			}
			else
				Bookint(Begin);
			cout << "按e返回主页面："; cin >> e;
			while (e != 'e')
			{
				cout << "按e返回主页面：";
				cin >> e;
			}
			system("cls");
			break;
		case 4:
			if (flagall == 0)
			{
				cout << "还未录入航班信息，请先进行信息录入！！！" << endl;
			}
			else
				Tuipiao(Begin);
			cout << "按e返回主页面："; cin >> e;
			while (e != 'e')
			{
				cout << "按e返回主页面：";
				cin >> e;
			}
			system("cls");
			break;
		default:
			break;
		}
	}



	cout << "这是主页面" << endl;
	//system("pause");
}