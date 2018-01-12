#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
//#include"Queue.h"
using namespace std;

//#include"Queue.h"

//�洢�油�ͻ���Ϣ�Ķ���(���������еķ�ʽ��ʵ�֣�
//�������ȶ���������ͣ�Ȼ���ٶ��������е�����

typedef struct qnode
{
	//Waiting_Customer *data;//�ͻ���Ϣ
	char name[10];//�ȴ��Ŀͻ�����
	int plane_num;//��Ҫ�Ļ�Ʊ��
	int level;     //��Ҫ�Ļ��յȼ�
	int id;        //�õȴ��ͻ��ı��
	struct qnode *next; //ָ����һ������ָ��
}DataNode; //���ӽ�������
typedef struct
{
	DataNode *front;//ָ����׽��
	DataNode *rear;//ָ���β���
}Waiting_LinkQuNode;

//��ʼ������
void InitQueue(Waiting_LinkQuNode*& q)
{
	q = (Waiting_LinkQuNode*)malloc(sizeof(Waiting_LinkQuNode));
	q->front = q->rear = NULL;
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Waiting_LinkQuNode *q)
{
	return q->rear == NULL;
}
//������
//����һ���½�����ڴ��Ԫ��e����pָ��������
//��ԭ����Ϊ�գ������ӽ����������ָ����p�����򽫽��p���ӵ��������ĩβ���������ӽ���rear��ָ����
void enQueue(Waiting_LinkQuNode*& q, int n)
{
	DataNode *pp1;
	pp1 = (DataNode*)malloc(sizeof(DataNode));//�����ȴ��ͻ���㣨�Լ���������)
											  //�õȴ��ͻ��ı��
	pp1->id = n;
	cout << "������Ҫ�ȴ��Ŀͻ�������" << '\t'; cin >> pp1->name;
	cout << "������Ҫ�ȴ��Ŀͻ������Ʊ�յȼ���" << '\t'; cin >> pp1->level;
	cout << "������Ҫ�ȴ��Ŀͻ������Ʊ������" << '\t'; cin >> pp1->plane_num;
	pp1->next = NULL;
	if (q->rear == NULL)   //������Ϊ�գ����½����Ƕ��׽�����Ƕ�β���
		q->front = q->rear = pp1;
	else
	{
		q->rear->next = pp1; //��pp1���������β������rearָ����
		q->rear = pp1;
	}
	cout << "���������" << endl;
}

//������
//��ԭ���в��գ����׽���dataֵ��ֵ���������ɾ��
//��ԭ����ֻ��һ����㣬���轫���ӽ��������������ΪNULL����ʾ�����Կ�
bool deQueue(Waiting_LinkQuNode*&q)
{
	DataNode *t;
	if (q->rear == NULL)  //��ԭ������Ϊ��
		return false;
	t = q->front; //tָ���׽��
	if (q->front == q->rear)  //ԭ��������ֻ��һ�����ݽ��ʱ
		q->front = q->rear = NULL;
	else                      //�����������������������ϵĽ��ʱ
		q->front = q->front->next;
	//free(t);//�ͷ����������ӵĽ�㣬�ȳ��Բ�д��
	return true;
}


//#include"test.h"

//�ɻ��ϸ��ȼ���ӵ�е�Ʊ����Ĭ��ֻ��һ�����Ȳգ�
typedef struct level
{
	int first;//һ�Ȳյ�����
	int Remaining_first;//ʣ���һ�Ȳյ�����
	int second;//���Ȳյ�����
	int Remaining_second;//ʣ��Ķ��Ȳ�����
	int third;//���Ȳյ�����
	int Remaining_third;//ʣ������Ȳ�����
	int all; //���������еĶ�Ʊ��
	int Remaining_all;//������������ʣ��Ʊ��
}level;
//�Ѷ�Ʊ�ĳ˿���Ϣ
typedef struct booking
{
	char Name[15];		//�˿�����
	char number[10];	//�˿����˷ɻ������
	char end[15];		//�˿��յ�վ
	level booked_level; //�˿������ķɻ�Ʊ�Ĳ�λ
	int id;             //ÿλ�Ѷ�Ʊ�ĳ˿Ͷ����Լ��Ķ������
	struct	booking *next;//��һ���˿�
}Booking_Customer;

//�ɻ�����ľ�����Ϣ
typedef struct
{
	char number[10];	//�����
	char planenum[10];	//�ɻ���
	char end[10];		//�յ�վ
	char date[10];		//��������
	level flight_level;	//��Ա������÷ɻ�һ�������ɶ����ˣ�
	int wait_count;			//�ŶӵȺ������
	int book_count;          //�Ѷ�Ʊ�ĳ˿�����
	Booking_Customer *head;	//�����Ѷ�Ʊ�ͻ�
	Waiting_LinkQuNode *Q;		//���Ӻ򲹿ͻ�����
}flight_info;
//���ϵͳ֮�����к���ļ��ϣ�Ҳ�������Ϊ����Ĭ�ϵ���һ�������ϵ����к�����Ϣ��
typedef struct all_flight
{
	flight_info data;
	all_flight *next;
}all_flight;


//#include"Insert.h"

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

//#include"Search.h"

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

//#include"Booking.h"

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

//#include"tuipiao.h"

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

void main3()
{
	all_flight *Begin; //�����б�ʼ
	int flagall = 0;
	char e;
	while (1)
	{
		int a_a;
		cout << '\t' << '\t' << "********************����ѡ����ҳ*************************" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           1--������Ϣ¼�빦��                       **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           2--������Ϣ��ѯ����                       **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           3--���ඩƱ����                           **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**           4--������Ʊ����                           **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "**                                                     **" << endl;
		cout << '\t' << '\t' << "*********************************************************" << endl;
		cout << '\t' << '\t' << "��������Ҫѡ��Ĺ���" << '\t'; cin >> a_a;
		system("cls");
		switch (a_a)
		{
		case 1:flagall = 1;
			Insert(Begin);
			cout << "��e������ҳ�棺"; cin >> e;
			while (e != 'e')
			{
				cout << "��e������ҳ�棺";
				cin >> e;
			}
			system("cls");
			break;
		case 2:
			if (flagall == 0)
			{
				cout << "��δ¼�뺽����Ϣ�����Ƚ�����Ϣ¼�룡����" << endl;
			}
			else
				Search(Begin);
			cout << "��e������ҳ�棺"; cin >> e;
			while (e != 'e')
			{
				cout << "��e������ҳ�棺";
				cin >> e;
			}
			system("cls");
			break;
		case 3:
			if (flagall == 0)
			{
				cout << "��δ¼�뺽����Ϣ�����Ƚ�����Ϣ¼�룡����" << endl;
			}
			else
				Bookint(Begin);
			cout << "��e������ҳ�棺"; cin >> e;
			while (e != 'e')
			{
				cout << "��e������ҳ�棺";
				cin >> e;
			}
			system("cls");
			break;
		case 4:
			if (flagall == 0)
			{
				cout << "��δ¼�뺽����Ϣ�����Ƚ�����Ϣ¼�룡����" << endl;
			}
			else
				Tuipiao(Begin);
			cout << "��e������ҳ�棺"; cin >> e;
			while (e != 'e')
			{
				cout << "��e������ҳ�棺";
				cin >> e;
			}
			system("cls");
			break;
		default:
			break;
		}
	}



	cout << "������ҳ��" << endl;
	//system("pause");
}