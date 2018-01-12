#include"a.h"

void main()
{
	int choice, j = 1;
	do
	{
		cout << "*********通 信 录*************" << endl;
		cout << "* 1．建立通讯录链表 *" << endl;
		cout << "* 2．插入通讯录信息 *" << endl;
		cout << "* 3．查询通讯录信息 *" << endl;
		cout << "* 4．删除通讯录信息 *" << endl;
		cout << "* 5．输出通讯录信息 *" << endl;
		cout << "* 6．退出通讯录管理系统 *" << endl;
		cout << "******************************" << endl << endl;
		cout << "         请选择菜单号(1--6):";
		cin >> choice;
		while (choice<1 || choice>6)
		{
			cout << "输入有错，请重新输入：" << endl;
			cin >> choice;
		}
		system("cls");
		switch (choice)
		{
		case 1:
		{
			cout << "*********************************************" << endl;
			cout << "\t* 建 立 通 讯 录 链 表 : *" << endl;
			cout << "*********************************************" << endl;
			head = CreateList();
			flag1 = 1;
			system("cls");
			break;
		}
		case 2:
		{
			if (flag1 != 1)
			{
				cout << endl << endl << " 通讯链表未建立，无法添加通讯人员信息!" << endl;
				cout << " 请先建立通讯链表!" << endl << endl;
			}
			else {
				cout << "***************************************" << endl;
				cout << "\t* 添 加 通 讯 录 信 息 : *" << endl;
				cout << "***************************************" << endl;
				cout << "请输入通讯人员的编号 姓名 性别 电话 地址 :" << endl;
				cout << "------------------------------------------- " << endl;
				ListNode *p;
				p= (ListNode *)malloc(sizeof(ListNode));                                 //申请新结点
				cout << "\n 编 号:\n";
				cin >> p->data.num;
				cout << "\n 姓 名:\n";
				cin >> p->data.name;
				cout << "\n 性 别:\n";
				cin >> p->data.sex;
				cout << "\n 电 话:\n";
				cin >> p->data.phone;
				cout << "\n 地 址:\n";
				cin >> p->data.addr;
				InsertNode(head, p);
				system("cls");
			}
			break;
		}
		case 3:
		{
			if (flag1 != 1)
			{
				cout << endl << endl << " 通讯链表未建立，无法查询通讯人员信息!" << endl;
				cout << "请先建立通讯链表!" << endl << endl;
			}
			else
			{
				cout << "****************************************" << endl;
				cout << "\t* 查 询 通 讯 录 信 息 ： *" << endl;
				cout << "****************************************" << endl;
				p = ListFind(head);
				if (p != NULL)
				{
					cout << "查询成功！ " << endl;
					cout << "通讯人员信息如下： " << endl;
					cout << "-----------------------------------------------" << endl;
					cout << "编 号:" << p->data.num << endl;
					cout << "姓 名:" << p->data.name << endl;
					cout << "性 别:" << p->data.sex << endl;
					cout << "电话:" << p->data.phone << endl;
					cout << "地 址:" << p->data.addr << endl;
					cout << "-----------------------------------------------" << endl;
					cout << endl<<endl<<'\t'<<'\t'<<"按e键返回主页面: ";
					char s;cin >> s;
					while (s != 'e')
					{
						cout << endl << endl << '\t' << '\t' << "按e键返回主页面: ";
						cin >> s;
					}
						system("cls");
				}
				else
				{
					cout << endl << endl << "查无此人！";
					cout << endl << endl << '\t' << '\t' << "按e键返回主页面: ";
					char s;cin >> s;
					while (s != 'e')
					{
						cout << endl << endl << '\t' << '\t' << "按e键返回主页面: ";
						cin >> s;
					}
					system("cls");
				}
			}
			break;
		}
		case 4:
		{
			if (flag1 != 1)
			{
				cout << endl << endl << " 通讯链表未建立，无法删除通讯人员信息!" << endl;
				cout << " 请先建立通讯链表!" << endl << endl;
			}
			else
			{
				cout << "****************************************" << endl;
				cout << "\t* 删 除 通 讯 录 信 息 *" << endl;
				cout << "****************************************" << endl;
				DelNode(head);                                            //删除结点
				cout << endl << endl << '\t' << '\t' << "按e键返回主页面: ";
				char s;cin >> s;
				while (s != 'e')
				{
					cout << endl << endl << '\t' << '\t' << "按e键返回主页面: ";
					cin >> s;
				}
				system("cls");
			}
			break;
		}
		case 5:
		{
			if (flag1 != 1)
			{
				cout << endl << endl << " 通讯链表未建立，无法输出通讯人员信息!" << endl;
				cout << " 请先建立通讯链表!" << endl << endl;
			}
			else
			{
				cout << "*****************************************" << endl;
				cout << "\t* 通 讯 录 链 表 的 输 出 *" << endl;
				cout << "*****************************************" << endl;
				PrintList(head);
				cout << endl << endl << '\t' << '\t' << "按e键返回主页面: ";
				char s;cin >> s;
				while (s != 'e')
				{
					cout << endl << endl << '\t' << '\t' << "按e键返回主页面: ";
					cin >> s;
				}
				system("cls");
			}
			break;
		}
		default:exit(0);break;
		}
	} while (choice !=0);
}