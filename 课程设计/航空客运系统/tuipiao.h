#pragma once
#pragma once
#include"test.h"
#include"Queue.h"

void Tuipiao(all_flight*& Begin)
{
	cout << endl << "------------------��ӭ������Ʊ����-------------------" << endl << endl;
	all_flight *p = Begin;//pָ����ǵ�ǰ��ѡ�еĺ���
	Booking_Customer *ppppp;//ppppָ��ָ����Ǻ���֮���Ѷ�Ʊ�ĳ˿�����
	Booking_Customer *qqqqq;//��Ϊ������ɾ����Ʊ�˿͵Ľ��
	Booking_Customer *ttttt;//���������ı���Ʊ�˿͵Ķ������
	Booking_Customer *rear;//����ָ��˿Ͷ�����β��
	int flag1 = 0, flag2 = 0;//flag1�������޸ú��࣬flag2����ú������޸ó˿�
							 //������Ʊ�ߵ�����������
	char exit_name[10]; char exit_num[10];
	cout << "�������������:" << '\t'; cin >> exit_name; cout << endl;
	cout << "��������ĺ���ţ�" << '\t'; cin >> exit_num; cout << endl;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->data.number, exit_num) == 0)
		{
			flag1 = 1;
			ppppp = p->data.head;
			qqqqq = p->data.head;
			ttttt = p->data.head;
			while (ppppp->next != NULL)//�ú������Ѷ�Ʊ�ĳ˿�
			{
				qqqqq = ppppp;
				ppppp = ppppp->next;
				if (strcmp(ppppp->Name, exit_name) == 0)//�ҵ��˸ó˿͵Ļ���Ҫ������Ѷ�Ʊ�˿�����֮��ɾ��
				{
					flag2 = 1;
					cout << ppppp->Name << " : ���������� " << p->data.number << " �ź��յ� " << ppppp->booked_level.all << " ��Ʊ�Ѿ���Ʊ�ɹ�������" << endl;
					if (ppppp->booked_level.first != 0)//�ó˿����˸ú���һ�Ȳյ�Ʊ����ú���һ�Ȳյ�ʣ��Ʊ����ʣ��Ʊ��Ҫ����
					{
						p->data.book_count--;//�˿�������һ
						p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first + ppppp->booked_level.first;
						p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all + ppppp->booked_level.first;
					}
					if (ppppp->booked_level.second != 0)//�ó˿����˸ú�����Ȳյ�Ʊ����ú���һ�Ȳյ�ʣ��Ʊ����ʣ��Ʊ��Ҫ����
					{
						p->data.book_count--;//�˿�������һ
						p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second + ppppp->booked_level.second;
						p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all + ppppp->booked_level.second;
					}
					if (ppppp->booked_level.third != 0)//�ó˿����˸ú������Ȳյ�Ʊ����ú���һ�Ȳյ�ʣ��Ʊ����ʣ��Ʊ��Ҫ����
					{
						p->data.book_count--;//�˿�������һ
						p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third + ppppp->booked_level.third;
						p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all + ppppp->booked_level.third;
					}
					//����ɾ��������,ɾ�����Ϳ�������ѭ����
					if (ppppp->next = NULL)
					{
						qqqqq->next = NULL;//break;
					}
					else
					{
						qqqqq->next = ppppp->next;//break;
					}
					//ɾ����֮�󣬱����ȴ����У�����з��������ģ��ͽ�����ӵ���Ʊ�˿��б�֮��
					if (p->data.wait_count == 0)
					{
						cout << "�ú���û�еȴ��油����Ա������" << endl;
					}
					else
					{
						switch (p->data.Q->front->level)
						{
						case 1:if (p->data.Q->front->plane_num < p->data.flight_level.Remaining_first)//����ȴ��ͻ������Ʊ��С�ڵ�ǰ�����ʣ���Ʊ��,��һ�Ȳ�
						{
							rear = p->data.head;
							//�������½�һ����Ʊ�˿ͽ�㣬Ȼ������β�巨���뵽�����Ѷ���Ʊ�ĳ˿�����֮��
							Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));
							while (rear->next != NULL)
							{
								rear = rear->next;
							}
							//�˿�����
							//book->Name = p->data.Q->front->name;
							cout << "������ȴ������еĳ˿�������" << p->data.Q->front->name << ")ȷ��Ϊ����ж�Ʊ��"; cin >> book->Name; cout << endl;
							cout << "�ɹ�Ϊ " << book->Name << " �˿Ͷ�Ʊ������" << endl;
							//�˿���Ҫ�ִ�ĳ���
							//book->end=p->data.Q->front.
							//�ó˿͵Ķ������
							p->data.book_count++;
							book->id = p->data.book_count;
							//�˿͵Ķ�Ʊ��
							book->booked_level.first = p->data.Q->front->plane_num;
							book->booked_level.all = p->data.Q->front->plane_num;
							p->data.flight_level.Remaining_first = p->data.flight_level.Remaining_first - p->data.Q->front->plane_num;//�ú���һ�Ȳ�ʣ��Ʊ��
							p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - p->data.Q->front->plane_num;//�ú�����ʣ��Ʊ��

							book->next = NULL;
							//β�������
							rear->next = book;
							rear = book;
							//�ͷ�ָ��
							rear = NULL; free(rear);

							//�����Ƿ��������ĳ˿ͳ�����,Ȼ�󽫸ú����еȴ��油������һ
							deQueue(p->data.Q);
							p->data.wait_count--;
						}
							   else
							   {
								   cout << "���˵�Ʊ�����ϳ˿�Ҫ���޷��Զ���Ʊ����" << endl;
							   }
							   break;
						case 2:if (p->data.Q->front->plane_num < p->data.flight_level.Remaining_second)
						{
							rear = p->data.head;
							//�������½�һ����Ʊ�˿ͽ�㣬Ȼ������β�巨���뵽�����Ѷ���Ʊ�ĳ˿�����֮��
							Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));
							while (rear->next != NULL)
							{
								rear = rear->next;
							}
							//�˿�����
							//book->Name = p->data.Q->front->name;
							cout << "������ȴ������еĳ˿�������" << p->data.Q->front->name << ")ȷ��Ϊ����ж�Ʊ��"; cin >> book->Name; cout << endl;
							cout << "�ɹ�Ϊ " << book->Name << " �˿Ͷ�Ʊ������" << endl;
							//�˿���Ҫ�ִ�ĳ���
							//book->end=p->data.Q->front.
							//�ó˿͵Ķ������
							p->data.book_count++;
							book->id = p->data.book_count;
							//�˿͵Ķ�Ʊ��
							book->booked_level.second = p->data.Q->front->plane_num;
							book->booked_level.all = p->data.Q->front->plane_num;
							p->data.flight_level.Remaining_second = p->data.flight_level.Remaining_second - p->data.Q->front->plane_num;//�ú�����Ȳ�ʣ��Ʊ��
							p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - p->data.Q->front->plane_num;//�ú�����ʣ��Ʊ��

							book->next = NULL;
							//β�������
							rear->next = book;
							rear = book;
							//�ͷ�ָ��
							rear = NULL; free(rear);

							//�����Ƿ��������ĳ˿ͳ�����,Ȼ�󽫸ú����еȴ��油������һ
							deQueue(p->data.Q);
							p->data.wait_count--;
						}
							   else
							   {
								   cout << "���˵�Ʊ�����ϳ˿�Ҫ���޷��Զ���Ʊ����" << endl;
							   }
							   break;
						case 3:if (p->data.Q->front->plane_num < p->data.flight_level.Remaining_third)
						{
							rear = p->data.head;
							//�������½�һ����Ʊ�˿ͽ�㣬Ȼ������β�巨���뵽�����Ѷ���Ʊ�ĳ˿�����֮��
							Booking_Customer *book = (Booking_Customer*)malloc(sizeof(Booking_Customer));
							while (rear->next != NULL)
							{
								rear = rear->next;
							}
							//�˿�����
							//book->Name = p->data.Q->front->name;
							cout << "������ȴ������еĳ˿�������" << p->data.Q->front->name << ")ȷ��Ϊ����ж�Ʊ��"; cin >> book->Name; cout << endl;
							cout << "�ɹ�Ϊ " << book->Name << " �˿Ͷ�Ʊ������" << endl;
							//�˿���Ҫ�ִ�ĳ���
							//book->end=p->data.Q->front.
							//�ó˿͵Ķ������
							p->data.book_count++;
							book->id = p->data.book_count;
							//�˿͵Ķ�Ʊ��
							book->booked_level.third = p->data.flight_level.third;
							book->booked_level.all = p->data.Q->front->plane_num;
							p->data.flight_level.Remaining_third = p->data.flight_level.Remaining_third - p->data.Q->front->plane_num;//�ú������Ȳ�ʣ��Ʊ��
							p->data.flight_level.Remaining_all = p->data.flight_level.Remaining_all - p->data.Q->front->plane_num;//�ú�����ʣ��Ʊ��

							book->next = NULL;
							//β�������
							rear->next = book;
							rear = book;
							//�ͷ�ָ��
							rear = NULL; free(rear);

							//�����Ƿ��������ĳ˿ͳ�����,Ȼ�󽫸ú����еȴ��油������һ
							deQueue(p->data.Q);
							p->data.wait_count--;
						}
							   else
							   {
								   cout << "���˵�Ʊ�����ϳ˿�Ҫ���޷��Զ���Ʊ����" << endl;
							   }
							   break;
						}
					}
				}
			}
			//�ı��Ѷ�Ʊ�ͻ��ı��
			int n = 0;
			while (ttttt->next != NULL)
			{
				n++;
				ttttt->id = n;
				ttttt = ttttt->next;
			}
			//�ͷ�ָ��
			ppppp = NULL; free(ppppp);
			qqqqq = NULL; free(qqqqq);
			ttttt = NULL; free(ttttt);
		}
	}
	if (flag1 == 1)
	{
		if (flag2 == 0)
			cout << "�ܱ�Ǹ���ú����Ѷ�Ʊ�˿�������Ϊ " << exit_name << " �ĳ˿ͣ���" << endl;
	}
	else
		cout << "�ܱ�Ǹ��û�����������Ϊ " << exit_num << " �ĺ��࣡��" << endl;
}