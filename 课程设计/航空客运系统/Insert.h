#pragma once
#pragma once
#include"test.h"
#include"Queue.h"

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