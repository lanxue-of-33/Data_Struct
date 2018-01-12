#pragma once
#pragma once
#include"test.h"
#include"Queue.h"

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