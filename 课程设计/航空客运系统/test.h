#pragma once
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include"Queue.h"
using namespace std;

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