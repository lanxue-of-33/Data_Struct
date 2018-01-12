#pragma once
#pragma once
#include"test.h"
#include"Insert.h"

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