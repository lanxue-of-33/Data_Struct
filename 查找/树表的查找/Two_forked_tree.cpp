#include"Two_forked_tree.h"

void maina()
{
	KeyType A[MAX];
	int n, t;
	cout << "��������Ҫ�����Ķ�����������" << endl;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "�������" << i + 1 << "�ؼ��ֵ�ֵ" << endl;
		cin >> A[i];
	}

	BSTNode *bt; //��Ҫ�����Ķ�����
	bt = CreateBST(A, n);

	BSTNode *b;//�����������������ҵ��Ľ��

	//�����ŷ���������������Ķ�����
	DisplayTree(bt);
	cout << endl;
	cout << "��������Ҫ���ҵ�Ԫ��:" << endl;
	cin >> t;
	cout << "�÷ǵݹ鷽���������·��" << endl;
	Non_recursion_search(bt, 6);
	cout << endl << "�õݹ鷽���������·��" << endl;
	Recursion_search(bt, t);
	//Dis(bt);
	system("pause");
}

