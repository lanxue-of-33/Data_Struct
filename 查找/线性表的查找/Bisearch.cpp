#include"Bisearch.h"

void main()
{
	int n, k;
	cout << "请输入你要创建的顺序表长度" << endl;
	cin >> n;
	cout << "请输入你要查找的数：" << endl;
	cin >> k;
	RecType Rs[Max];
	create(Rs, n);
	cout << "其在第" << BinSearch(Rs, n, k) << "个位置上" << endl;
	system("pause");
}