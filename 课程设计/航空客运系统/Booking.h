#pragma once
#pragma once
#include"test.h"

void Bookint(all_flight*&Begin)
{
	cout << endl << "-------------------��ӭ������������-------------------" << endl << endl;
	all_flight *p = Begin;
	all_flight *pppp = Begin;//ָ��ppppָ�򺽰�����ĵ�һ��������ݣ����������Ƽ������õ�
	Booking_Customer*rear;
	//Booking_Customer *rear1;//rearָ��ָ��ͻ������ĩβ,rear1�ǵ������Ƽ�����ʱ������ָ��ǰ����ͻ��������ĩβ
	int flag1 = 0;//�����ж��Ƿ��з��ϳ˿�Ҫ��ĺ����
	char number[10];//��Ʊ�ĺ����
	int level;      //��������Ҫ�����Ĳ�λ
	int booking_num;//��Ҫ��Ʊ������
	cout << "��������Ҫ�����ĺ���ţ�" << '\t'; cin >> number;
	cout << "��������Ҫ�����Ĳ�λ��" << '\t'; cin >> level;
	cout << "��������ҪԤ����Ʊ����" << '\t'; cin >> booking_num;
	while (p->next != NULL)
	{
		p = p->next; //p����ľ��ǵ�ǰ����
		if (strcmp(p->data.number, number) == 0)
		{
			flag1 = 1;//��ʾ�з��ϳ˿�Ҫ��ĺ����
			switch (level)
			{
			case 1:if (booking_num > p->data.flight_level.Remaining_first)
			{
				cout << "�Բ��𣬸ò�λ��ʣ��Ʊ��������ҪԤ����Ʊ����" << endl;
				cout << "�����Ƿ���Ҫ����ȴ��油�Ŀͻ���������1��ʾ���룬��2���к����Ƽ�,��3�뿪�������棩" << '\t';
				int tui; cin >> tui;
				switch (tui)
				{
				case 1:p->data.wait_count++;
					cout << "���ǵȴ������еĵ�" << p->data.wait_count << "λ�˿�" << endl;
					enQueue(p->data.Q, p->data.wait_count);
					cout << "�����ɹ�����Ʊʱ���ǽ�Ϊ�����ȳ�Ʊ������" << endl;
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
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer *rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ���(" << pppp->data.end << ")" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.first = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_first = pppp->data.flight_level.Remaining_first - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);

									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						case 2:if (pppp->data.flight_level.Remaining_second < booking_num);
							if (pppp->data.flight_level.Remaining_second > booking_num)
							{
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer*	rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ��У�" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.second = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_second = pppp->data.flight_level.Remaining_second - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						case 3:if (pppp->data.flight_level.Remaining_third < booking_num);
							if (pppp->data.flight_level.Remaining_third > booking_num)
							{
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer* rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ��У�" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.third = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_third = pppp->data.flight_level.Remaining_third - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						}
					}
				}
				default:
					cout << "��ӭ���´�������Ʊ������" << endl;
					break;
				}
			}
				   else
				   {
					   rear = p->data.head;//rearָ��ָ��ǰ����ͻ������β���
					   cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
					   //������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
					   Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
					   while (rear->next != NULL)
					   {
						   rear = rear->next;
					   }
					   cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
					   cout << "��������Ҫ�ִ�ĳ���(" << p->data.end << ")" << '\t'; cin >> book->end;
					   cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
					   cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
					   //�ó˿͵Ķ������
					   p->data.book_count++;
					   book->id = p->data.book_count;
					   //���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
					   book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
					   cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
					   switch (level)
					   {
					   case 1:book->booked_level.first = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
						   break;
					   case 2:book->booked_level.second = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - booking_num;//�ú�����Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
						   break;
					   case 3:book->booked_level.third = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - booking_num;//�ú������Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
					   default:
						   break;
					   }
					   book->next = NULL;
					   //β�������
					   rear->next = book;
					   rear = book;
					   //��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
					   rear = NULL; free(rear);
					   //book->next = NULL;
					   //rear = book->next;
					   //free(rear);
				   }
				   break;
			case 2:if (booking_num > p->data.flight_level.Remaining_second)
			{
				cout << "�Բ��𣬸ò�λ��ʣ��Ʊ��������ҪԤ����Ʊ����" << endl;
				cout << "�����Ƿ���Ҫ����ȴ��油�Ŀͻ���������1��ʾ���룬��2���к����Ƽ�,��3�뿪�������棩" << '\t';
				int tui; cin >> tui;
				switch (tui)
				{
				case 1:p->data.wait_count++;
					cout << "���ǵȴ������еĵ�" << p->data.wait_count << "λ�˿�" << endl;
					enQueue(p->data.Q, p->data.wait_count);
					cout << "�����ɹ�����Ʊʱ���ǽ�Ϊ�����ȳ�Ʊ������" << endl;
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
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer *rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ���(" << pppp->data.end << ")" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.first = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_first = pppp->data.flight_level.Remaining_first - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);

									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						case 2:if (pppp->data.flight_level.Remaining_second < booking_num);
							if (pppp->data.flight_level.Remaining_second > booking_num)
							{
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer*	rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ��У�" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.second = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_second = pppp->data.flight_level.Remaining_second - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						case 3:if (pppp->data.flight_level.Remaining_third < booking_num);
							if (pppp->data.flight_level.Remaining_third > booking_num)
							{
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer* rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ��У�" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.third = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_third = pppp->data.flight_level.Remaining_third - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						}
					}
				}
				default:
					cout << "��ӭ���´�������Ʊ������" << endl;
					break;
				}
			}
				   else
				   {
					   rear = p->data.head;//rearָ��ָ��ͻ������β���
					   cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
					   //������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
					   Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
					   while (rear->next != NULL)
					   {
						   rear = rear->next;
					   }
					   cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
					   cout << "��������Ҫ�ִ�ĳ���(" << p->data.end << ")" << '\t'; cin >> book->end;
					   cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
					   cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
					   //���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
					   book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
					   cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
					   //�ó˿͵Ķ������
					   p->data.book_count++;
					   book->id = p->data.book_count;
					   switch (level)
					   {
					   case 1:book->booked_level.first = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
						   break;
					   case 2:book->booked_level.second = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - booking_num;//�ú�����Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
						   break;
					   case 3:book->booked_level.third = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - booking_num;//�ú������Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
					   default:
						   break;
					   }
					   book->next = NULL;
					   //β�������
					   rear->next = book;
					   rear = book;
					   //��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
					   rear = NULL; free(rear);
					   // book->next = NULL;
					   //rear = book->next;
					   //free(rear);
				   }
				   break;
			case 3:if (booking_num > p->data.flight_level.Remaining_third)
			{
				cout << "�Բ��𣬸ò�λ��ʣ��Ʊ��������ҪԤ����Ʊ����" << endl;
				cout << "�����Ƿ���Ҫ����ȴ��油�Ŀͻ���������1��ʾ���룬��2���к����Ƽ�,��3�뿪�������棩" << '\t';
				int tui; cin >> tui;
				switch (tui)
				{
				case 1:p->data.wait_count++;
					cout << "���ǵȴ������еĵ�" << p->data.wait_count << "λ�˿�" << endl;
					enQueue(p->data.Q, p->data.wait_count);
					cout << "�����ɹ�����Ʊʱ���ǽ�Ϊ�����ȳ�Ʊ������" << endl;
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
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer *rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ���(" << pppp->data.end << ")" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.first = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_first = pppp->data.flight_level.Remaining_first - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);

									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						case 2:if (pppp->data.flight_level.Remaining_second < booking_num);
							if (pppp->data.flight_level.Remaining_second > booking_num)
							{
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer*	rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ��У�" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.second = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_second = pppp->data.flight_level.Remaining_second - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						case 3:if (pppp->data.flight_level.Remaining_third < booking_num);
							if (pppp->data.flight_level.Remaining_third > booking_num)
							{
								cout << "�����Ϊ��" << pppp->data.number << "�ĺ����з�����Ҫ���Ʊ�������Ƿ�Ʊ����1�ǣ���2�񣩣���";
								int kk; cin >> kk;
								if (kk == 1)
								{
									//���ó˿ͼ��뵽��������ѯ�������˺���֮��
									Booking_Customer* rear1 = pppp->data.head;//rearָ��ָ��ǰ����ͻ������β���
									cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
									//������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
									Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
									while (rear1->next != NULL)
									{
										rear1 = rear1->next;
									}
									cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
									cout << "��������Ҫ�ִ�ĳ��У�" << '\t'; cin >> book->end;
									cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
									cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
									pppp->data.book_count++;
									book->id = p->data.book_count;
									//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
									book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
									cout << "���������Ʊ������ȷ��" << "(" << pppp->data.number << "):" << '\t'; cin >> booking_num; cout << endl;
									book->booked_level.third = booking_num;
									book->booked_level.all = booking_num;
									pppp->data.flight_level.Remaining_third = pppp->data.flight_level.Remaining_third - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
									pppp->data.flight_level.Remaining_all = pppp->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
									book->next = NULL;
									//β�������
									rear1->next = book;
									rear1 = book;
									//��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
									//book->next = NULL;
									rear1 = NULL; free(rear1);
									//free(rear1);
									//���뵽�������Ƽ��ĺ���Ŀͻ��б������гɹ�
									cout << "��ϲ�㣺" << book->Name << "��ȥ�� " << book->end << " �ĺ��� " << book->number << " ��Ʊ�ɹ�������" << endl;
								}
								else
									cout << "�ܱ�Ǹ���ú���û�������⣬�����������ǵ���Ϣ��" << endl;
							}
							break;
						}
					}
				}
				default:
					cout << "��ӭ���´�������Ʊ������" << endl;
					break;
				}
			}
				   else
				   {
					   rear = p->data.head;//rearָ��ָ��ͻ������β���
					   cout << "��ϲ�㣬�ò�λƱ�����㣬�����������������Ϣ���ж�Ʊ������" << endl;
					   //������������һ�������ͻ���㣬������뵽������Ķ����ͻ�����֮��
					   Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));//����ռ�
					   while (rear->next != NULL)
					   {
						   rear = rear->next;
					   }
					   cout << "���������������" << '\t'; cin >> book->Name; cout << endl;
					   cout << "��������Ҫ�ִ�ĳ���(" << p->data.end << ")" << '\t'; cin >> book->end;
					   cout << "��ȷ��������ĺ���Ž���ȷ��" << "(" << number << "):" << '\t'; cin >> book->number; cout << endl;
					   cout << "��������Ĳ�λ����ȷ��" << "(" << level << "):" << '\t'; cin >> level; cout << endl;
					   //���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
					   book->booked_level.first = book->booked_level.second = book->booked_level.third = 0;
					   cout << "���������Ʊ������ȷ��" << "(" << booking_num << "):" << '\t'; cin >> booking_num; cout << endl;
					   //�ó˿͵Ķ������
					   p->data.book_count++;
					   book->id = p->data.book_count;
					   switch (level)
					   {
					   case 1:book->booked_level.first = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - booking_num;//�ú���һ�Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
						   break;
					   case 2:book->booked_level.second = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - booking_num;//�ú�����Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
						   break;
					   case 3:book->booked_level.third = booking_num;
						   book->booked_level.all = booking_num;
						   p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - booking_num;//�ú������Ȳ�ʣ��Ʊ��
						   p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - booking_num;//�ú�����ʣ��Ʊ��
					   default:
						   break;
					   }
					   book->next = NULL;
					   //β�������
					   rear->next = book;
					   rear = book;
					   //��������д�����Ϊ���ͷŵ�rearָ�룬Ϊ�ٴε�����׼����
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
		cout << "�ܱ�Ǹ����û����Ҫ���ĺ�����������" << endl;
	rear = NULL;
	p = NULL;
	pppp = NULL;
}
