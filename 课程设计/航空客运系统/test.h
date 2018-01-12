#pragma once
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include"Queue.h"
using namespace std;

//飞机上各等级所拥有的票数（默认只有一二三等舱）
typedef struct level
{
	int first;//一等舱的数量
	int Remaining_first;//剩余的一等舱的数量
	int second;//二等舱的数量
	int Remaining_second;//剩余的二等舱数量
	int third;//三等舱的数量
	int Remaining_third;//剩余的三等舱数量
	int all; //加起来所有的订票数
	int Remaining_all;//加起来的所有剩余票数
}level;
//已订票的乘客信息
typedef struct booking
{
	char Name[15];		//乘客姓名
	char number[10];	//乘客所乘飞机航班号
	char end[15];		//乘客终点站
	level booked_level; //乘客所定的飞机票的舱位
	int id;             //每位已订票的乘客都有自己的订单编号
	struct	booking *next;//下一个乘客
}Booking_Customer;

//飞机航班的具体信息
typedef struct
{
	char number[10];	//航班号
	char planenum[10];	//飞机号
	char end[10];		//终点站
	char date[10];		//飞行日期
	level flight_level;	//成员定额（即该飞机一次能容纳多少人）
	int wait_count;			//排队等候的人数
	int book_count;          //已订票的乘客数量
	Booking_Customer *head;	//链接已订票客户
	Waiting_LinkQuNode *Q;		//链接候补客户队列
}flight_info;
//这个系统之内所有航班的集合（也可以理解为我们默认的这一条航线上的所有航班信息）
typedef struct all_flight
{
	flight_info data;
	all_flight *next;
}all_flight;