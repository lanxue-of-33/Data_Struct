#include"Bisearch.h"

void main()
{
	int n, k;
	cout << "��������Ҫ������˳�����" << endl;
	cin >> n;
	cout << "��������Ҫ���ҵ�����" << endl;
	cin >> k;
	RecType Rs[Max];
	create(Rs, n);
	cout << "���ڵ�" << BinSearch(Rs, n, k) << "��λ����" << endl;
	system("pause");
}