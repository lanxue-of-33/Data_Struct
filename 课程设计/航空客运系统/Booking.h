#pragma once
#pragma once
#include"test.h"

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
