#pragma once
#include<iostream>
#include<string.h>
typedef int KeyType;
typedef char InfoType;
#define Max 100
using namespace std;

typedef struct
{
	KeyType key;
	InfoType data;//其它数据项
}RecType;

//顺序查找
int SeqSearch(RecType R[], int n, KeyType k)
{
	int i = 0;
	while (i<n&&R[i].key != k) //从表头往后找
		i++;
	if (i >= n)
		return 0;
	else
		return i + 1; //找到就返回逻辑序号加一
}

//折半查找
int BinSearch(RecType R[], int n, KeyType k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)     //当前区间存在元素时循环
	{
		mid = (low + high) / 2;
		cout << "与折半值" << R[mid].key << "比" << endl;
		if (k == R[mid].key) //查找成功返回其逻辑序号加一
		{
			cout << "查找成功!" << endl;
			return mid + 1;
		}
		if (k<R[mid].key)  //继续在R[low...mid-1]中查找
		{
			cout << k<<"的值比折半的值"<<R[mid].key<<"更小，所以将high变成mid-1，在继续查找" << endl;
			high = mid - 1;
		}
		else              //k>R[mid].key
		{
			cout << k<<"的值比折半的值"<<R[mid].key<<"更大，所以将low变成mid+1，在继续查找" << endl;
			low = mid + 1;    //继续在R[mid+1...high]中查找
		}
	}
	return 0; //查找失败
}

//为顺序表赋值
void create(RecType R[], int &n)
{
	for (int i = 0; i<n; i++)
	{
		cout << "请输入第" << i + 1 << "个数据" << endl;
		cin >> R[i].key;
	}
	cout << "输入完成" << endl << endl;
}