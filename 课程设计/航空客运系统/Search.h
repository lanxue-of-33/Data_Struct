#pragma once
#pragma once
#include"test.h"
#include"Insert.h"

void Search(all_flight*& Begin)
{
	cout << "-------------------��ӭ����������Ϣ��ѯ����--------------------" << endl << endl;
	all_flight *p, *q;
	// = Begin->next;q = Begin->next;
	char flag = 'e';
	int choice;
	char hangbanhao[10];
	char city[10];
	while (flag == 'e')
	{
		p = Begin->next; q = Begin->next;
		cout << "������Ų�ѯ��1����2�ǰ���ɵִ���в�ѯ�ɻ��������" << endl;
		cout << "�������ѯ��ʽ" << endl; cin >> choice;
		switch (choice)
		{
		case 1:cout << "��������Ҫ��ѯ�ĺ���ţ�"; cin >> hangbanhao;
			while (p != NULL)
			{
				if (strcmp(p->data.number, hangbanhao) == 0)
				{
					cout << "�ú�������ʱ��Ϊ��" << '\t' << p->data.date << endl;
					cout << "�ú���ĵִ����Ϊ��" << '\t' << p->data.end << endl;
					cout << "�ú������г˿�����" << '\t' << p->data.book_count << endl;
					cout << "�ú���Ⱥ��油�˿�����" << '\t' << p->data.wait_count << endl;
					cout << "�ú������Ʊ�������£�" << endl;
					cout << "ʣ��һ�Ȳյ�Ʊ����" << '\t' << p->data.flight_level.Remaining_first << endl;
					cout << "ʣ����Ȳյ�Ʊ����" << '\t' << p->data.flight_level.Remaining_second << endl;
					cout << "ʣ�����Ȳյ�Ʊ����" << '\t' << p->data.flight_level.Remaining_third << endl;
					cout << "��ʣƱ��Ϊ�� " << '\t' << p->data.flight_level.Remaining_all << endl;
					//cout << "��1�鿴һ��Ʊ�ĳ˿;�����Ϣ����2���鿴";
					p = p->next;
				}
				else
				{
					p = p->next;
				}
			} break;
		case 2:cout << "��������Ҫ�ִ�ĳ���:"; cin >> city;
			while (q != NULL)
			{
				if (strcmp(q->data.end, city) == 0)//�ж������ַ����Ƿ����
				{
					cout << "����ó��еĺ����Ϊ:" << '\t' << q->data.number << endl;
					cout << "�ú�������ʱ��Ϊ:" << '\t' << q->data.date << endl;
					cout << "�ú���ķɻ���Ϊ��" << '\t' << q->data.planenum << endl;
					cout << "�ú������г˿�����" << '\t' << q->data.book_count << endl;
					cout << "�ú���Ⱥ��油�˿�����" << '\t' << q->data.wait_count << endl;
					cout << "�ú������Ʊ�������£�" << endl;
					cout << "ʣ��һ�Ȳյ�Ʊ����" << '\t' << q->data.flight_level.Remaining_first << endl;
					cout << "ʣ����Ȳյ�Ʊ����" << '\t' << q->data.flight_level.Remaining_second << endl;
					cout << "ʣ�����Ȳյ�Ʊ����" << '\t' << q->data.flight_level.Remaining_third << endl;
					cout << "��ʣƱ��Ϊ�� " << '\t' << q->data.flight_level.Remaining_all << endl;
					q = q->next;
				}
				else
					q = q->next;
			}
		default:
			break;
		}
		cout << "�Ƿ������ѯ������e'������ѯ������a���˳���ѯ��:  "; cin >> flag;
	}
	//��ѯ��Ϻ������һ��
	//system("cls");
}