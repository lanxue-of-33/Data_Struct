#include"a.h"

void main()
{
	int choice, j = 1;
	do
	{
		cout << "*********ͨ �� ¼*************" << endl;
		cout << "* 1������ͨѶ¼���� *" << endl;
		cout << "* 2������ͨѶ¼��Ϣ *" << endl;
		cout << "* 3����ѯͨѶ¼��Ϣ *" << endl;
		cout << "* 4��ɾ��ͨѶ¼��Ϣ *" << endl;
		cout << "* 5�����ͨѶ¼��Ϣ *" << endl;
		cout << "* 6���˳�ͨѶ¼����ϵͳ *" << endl;
		cout << "******************************" << endl << endl;
		cout << "         ��ѡ��˵���(1--6):";
		cin >> choice;
		while (choice<1 || choice>6)
		{
			cout << "�����д����������룺" << endl;
			cin >> choice;
		}
		system("cls");
		switch (choice)
		{
		case 1:
		{
			cout << "*********************************************" << endl;
			cout << "\t* �� �� ͨ Ѷ ¼ �� �� : *" << endl;
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
				cout << endl << endl << " ͨѶ����δ�������޷����ͨѶ��Ա��Ϣ!" << endl;
				cout << " ���Ƚ���ͨѶ����!" << endl << endl;
			}
			else {
				cout << "***************************************" << endl;
				cout << "\t* �� �� ͨ Ѷ ¼ �� Ϣ : *" << endl;
				cout << "***************************************" << endl;
				cout << "������ͨѶ��Ա�ı�� ���� �Ա� �绰 ��ַ :" << endl;
				cout << "------------------------------------------- " << endl;
				ListNode *p;
				p= (ListNode *)malloc(sizeof(ListNode));                                 //�����½��
				cout << "\n �� ��:\n";
				cin >> p->data.num;
				cout << "\n �� ��:\n";
				cin >> p->data.name;
				cout << "\n �� ��:\n";
				cin >> p->data.sex;
				cout << "\n �� ��:\n";
				cin >> p->data.phone;
				cout << "\n �� ַ:\n";
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
				cout << endl << endl << " ͨѶ����δ�������޷���ѯͨѶ��Ա��Ϣ!" << endl;
				cout << "���Ƚ���ͨѶ����!" << endl << endl;
			}
			else
			{
				cout << "****************************************" << endl;
				cout << "\t* �� ѯ ͨ Ѷ ¼ �� Ϣ �� *" << endl;
				cout << "****************************************" << endl;
				p = ListFind(head);
				if (p != NULL)
				{
					cout << "��ѯ�ɹ��� " << endl;
					cout << "ͨѶ��Ա��Ϣ���£� " << endl;
					cout << "-----------------------------------------------" << endl;
					cout << "�� ��:" << p->data.num << endl;
					cout << "�� ��:" << p->data.name << endl;
					cout << "�� ��:" << p->data.sex << endl;
					cout << "�绰:" << p->data.phone << endl;
					cout << "�� ַ:" << p->data.addr << endl;
					cout << "-----------------------------------------------" << endl;
					cout << endl<<endl<<'\t'<<'\t'<<"��e��������ҳ��: ";
					char s;cin >> s;
					while (s != 'e')
					{
						cout << endl << endl << '\t' << '\t' << "��e��������ҳ��: ";
						cin >> s;
					}
						system("cls");
				}
				else
				{
					cout << endl << endl << "���޴��ˣ�";
					cout << endl << endl << '\t' << '\t' << "��e��������ҳ��: ";
					char s;cin >> s;
					while (s != 'e')
					{
						cout << endl << endl << '\t' << '\t' << "��e��������ҳ��: ";
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
				cout << endl << endl << " ͨѶ����δ�������޷�ɾ��ͨѶ��Ա��Ϣ!" << endl;
				cout << " ���Ƚ���ͨѶ����!" << endl << endl;
			}
			else
			{
				cout << "****************************************" << endl;
				cout << "\t* ɾ �� ͨ Ѷ ¼ �� Ϣ *" << endl;
				cout << "****************************************" << endl;
				DelNode(head);                                            //ɾ�����
				cout << endl << endl << '\t' << '\t' << "��e��������ҳ��: ";
				char s;cin >> s;
				while (s != 'e')
				{
					cout << endl << endl << '\t' << '\t' << "��e��������ҳ��: ";
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
				cout << endl << endl << " ͨѶ����δ�������޷����ͨѶ��Ա��Ϣ!" << endl;
				cout << " ���Ƚ���ͨѶ����!" << endl << endl;
			}
			else
			{
				cout << "*****************************************" << endl;
				cout << "\t* ͨ Ѷ ¼ �� �� �� �� �� *" << endl;
				cout << "*****************************************" << endl;
				PrintList(head);
				cout << endl << endl << '\t' << '\t' << "��e��������ҳ��: ";
				char s;cin >> s;
				while (s != 'e')
				{
					cout << endl << endl << '\t' << '\t' << "��e��������ҳ��: ";
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