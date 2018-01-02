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
	InfoType data;//����������
}RecType;

//˳�����
int SeqSearch(RecType R[], int n, KeyType k)
{
	int i = 0;
	while (i<n&&R[i].key != k) //�ӱ�ͷ������
		i++;
	if (i >= n)
		return 0;
	else
		return i + 1; //�ҵ��ͷ����߼���ż�һ
}

//�۰����
int BinSearch(RecType R[], int n, KeyType k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)     //��ǰ�������Ԫ��ʱѭ��
	{
		mid = (low + high) / 2;
		cout << "���۰�ֵ" << R[mid].key << "��" << endl;
		if (k == R[mid].key) //���ҳɹ��������߼���ż�һ
		{
			cout << "���ҳɹ�!" << endl;
			return mid + 1;
		}
		if (k<R[mid].key)  //������R[low...mid-1]�в���
		{
			cout << k<<"��ֵ���۰��ֵ"<<R[mid].key<<"��С�����Խ�high���mid-1���ڼ�������" << endl;
			high = mid - 1;
		}
		else              //k>R[mid].key
		{
			cout << k<<"��ֵ���۰��ֵ"<<R[mid].key<<"�������Խ�low���mid+1���ڼ�������" << endl;
			low = mid + 1;    //������R[mid+1...high]�в���
		}
	}
	return 0; //����ʧ��
}

//Ϊ˳���ֵ
void create(RecType R[], int &n)
{
	for (int i = 0; i<n; i++)
	{
		cout << "�������" << i + 1 << "������" << endl;
		cin >> R[i].key;
	}
	cout << "�������" << endl << endl;
}