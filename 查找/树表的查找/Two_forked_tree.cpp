#include"Two_forked_tree.h"

void maina()
{
	KeyType A[MAX];
	int n, t;
	cout << "请输入你要创建的二叉树结点个数" << endl;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "请输入第" << i + 1 << "关键字的值" << endl;
		cin >> A[i];
	}

	BSTNode *bt; //所要创建的二叉树
	bt = CreateBST(A, n);

	BSTNode *b;//用来接受我们所查找到的结点

	//用括号法输出我们所创建的二叉树
	DisplayTree(bt);
	cout << endl;
	cout << "请输入你要查找的元素:" << endl;
	cin >> t;
	cout << "用非递归方法输出查找路径" << endl;
	Non_recursion_search(bt, 6);
	cout << endl << "用递归方法输出查找路径" << endl;
	Recursion_search(bt, t);
	//Dis(bt);
	system("pause");
}

