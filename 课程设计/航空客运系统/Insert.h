#pragma once
#pragma once
#include"test.h"
#include"Queue.h"

//������Ϣ¼��
void Insert(all_flight*& Begin)
{
	cout << endl << "----------------��ӭ����������Ϣ¼�����----------------" << endl << endl;
	all_flight *s, *p; //pָ��ʼ��ָ�������ĩβ
	Begin = (all_flight*)malloc(sizeof(all_flight));
	p = Begin;
	cout << "��������Ҫ����ĺ�������"; int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		s = (all_flight*)malloc(sizeof(all_flight)); //������
		cout << "�����뺽��ţ�" << endl;
		cin >> s->data.number; //����ָ�򺽰��ʱ�������á�->����ֻ���á�.��,��Ϊ�ⲻ��ָ��
		cout << "������ɻ��ţ�" << endl;
		cin >> s->data.planenum;
		cout << "�������յ�վ��" << endl;
		cin >> s->data.end;
		cout << "������������ڣ�" << endl;
		cin >> s->data.date;
		cout << "�������Ա���" << endl;
		cout << "������ú���һ�Ȳյ�����" << endl; cin >> s->data.flight_level.first;
		cout << "������ú�����Ȳյ�����" << endl; cin >> s->data.flight_level.second;
		cout << "������ú������Ȳյ�����" << endl; cin >> s->data.flight_level.third;
		s->data.flight_level.all = s->data.flight_level.first + s->data.flight_level.second + s->data.flight_level.third;
		s->data.flight_level.Remaining_first = s->data.flight_level.first;
		s->data.flight_level.Remaining_second = s->data.flight_level.second;
		s->data.flight_level.Remaining_third = s->data.flight_level.third;
		s->data.flight_level.Remaining_all = s->data.flight_level.all;
		cout << "�ú����Ա�����Ʊ��������Ϊ��" << s->data.flight_level.all << endl;

		cout << "�����������Ѿ���Ʊ�ĳ˿���Ϣ" << endl;
		Booking_Customer *pp, *p1;
		s->data.book_count = 0;
		//������Ϊ�������е��Ѷ����˿��������洢�ռ�
		s->data.head = (Booking_Customer*)malloc(sizeof(Booking_Customer));//��û�����������洢�ռ�ʱ�����
		pp = s->data.head;//pp������ָ��ó˿���Ϣ�����ĩβ��
		cout << "����1��ʼ�����Ѿ���Ʊ�ĳ˿���Ϣ" << endl;
		int a; cin >> a;
		if (a == 1)
		{
			while (a == 1)
			{
				s->data.book_count++; //��ǰ������Ѿ���Ʊ�ĳ˿�����
				p1 = (Booking_Customer*)malloc(sizeof(Booking_Customer));//�½��Ѷ�Ʊ�˿ͽ��
				cout << "�������" << s->data.book_count << "λ�˿͵���Ϣ" << endl;
				cout << "�䶩�����Ϊ��" << '\t' << s->data.book_count << endl; p1->id = s->data.book_count;
				cout << "��������������" << '\t';   cin >> p1->Name; cout << endl;
				cout << "�����뺽��ţ�" << s->data.number << ")����ȷ�ϣ�"; cin >> p1->number; cout << endl;
				cout << "������ִ���У�" << s->data.end << "������ȷ�ϣ�"; cin >> p1->end; cout << endl;
				cout << "�����붩Ʊ�Ĳ�λ�ȼ���" << '\t'; int aa; cin >> aa; cout << endl;
				//���˿͵Ķ�Ʊ�����ȳ�ʼ��Ϊ0
				p1->booked_level.first = p1->booked_level.second = p1->booked_level.third = 0;
				cout << "�������䶩Ʊ����" << '\t';  int bb; cin >> bb; cout << endl;
				switch (aa)
				{
				case 1:p1->booked_level.first = bb;
					p1->booked_level.all = p1->booked_level.first;
					s->data.flight_level.Remaining_first = s->data.flight_level.first - p1->booked_level.first;//�ú�����ʣ�µ�һ�Ȳյ�Ʊ��
					s->data.flight_level.Remaining_all = s->data.flight_level.Remaining_all - p1->booked_level.first;//�ú�����ʣ�µ�����Ʊ��
					break;
				case 2:p1->booked_level.second = bb;
					p1->booked_level.all = p1->booked_level.second;
					s->data.flight_level.Remaining_second = s->data.flight_level.second - p1->booked_level.second;//�ú�����ʣ�µĶ��Ȳյ�Ʊ��
					s->data.flight_level.Remaining_all = s->data.flight_level.Remaining_all - p1->booked_level.second;//�ú�����ʣ�µ�����Ʊ��
					break;
				case 3:p1->booked_level.third = bb;
					p1->booked_level.all = p1->booked_level.third;
					s->data.flight_level.Remaining_third = s->data.flight_level.third - p1->booked_level.third;//�ú�����ʣ�µ����Ȳյ�Ʊ��
					s->data.flight_level.Remaining_all = s->data.flight_level.Remaining_all - p1->booked_level.third;//�ú�����ʣ�µ�����Ʊ��
				default:
					break;
				}
				cout << "�ó˿Ͷ���" << p1->booked_level.all << "��Ʊ��" << endl;
				cout << "����1��������˿���Ϣ������2�˳�����˿���Ϣ";
				//���õ���β�巨���½��ĳ˿���Ϣ�����뵽�Ѷ�Ʊ�˿������ĩβ
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
			cout << "�ú�����ʱû���Ѷ�Ʊ�ĳ˿͡�" << endl;
		}
		cout << endl;
		//free(pp);

		//�������������油�ͻ�����Ϣ
		InitQueue(s->data.Q); //��ʼ���ȴ��油�ͻ��Ķ���
							  //Waiting_LinkQuNode *q;
		s->data.wait_count = 0;
		int aaa; int mmm = 0;
		cout << "�Ƿ��еȴ��油�ĳ˿ͣ�1�����У�2����û�У�"; cin >> aaa;
		if (aaa == 1)
		{
			cout << "������¼��ȴ��油�ĳ˿���Ϣ��" << endl;
			while (aaa == 1)
			{
				s->data.wait_count++; mmm++;
				cout << "�ÿͻ�Ϊ�����еĵ�" << s->data.wait_count << "λ�˿�" << endl;
				enQueue(s->data.Q, s->data.wait_count);
				cout << "����1�����������ȴ��˿͵���Ϣ��" << endl;
				cin >> aaa;
			}
			cout << "��ѭ����" << mmm << "��" << endl << endl;
		}
		else
		{
			cout << "�ú�������û�еȴ��油�ĳ˿͡�" << endl << endl;
		}


		//����β�巨�����㣨���뺽����Ϣ��
		p->next = s;
		p = s;
	}
	p->next = NULL; //��β����nextֵ����Ϊ��

					//������Ϻ�ʹ����������������һ��
	cout << endl << endl;
	/*cout << "����e����������" << endl;
	char e;cin >> e;
	if(e=='e')
	system("cls");*/
}