//#include <iostream>
//
//using namespace std;
//
//typedef struct threadTreeNode
//{
//	char data;
//	threadTreeNode *left, *right;
//	bool right_thread;
//} TreeNode;
//
//// ��� p�� ���� �ļ��� (inorder successor) ã��
//TreeNode *find_successor(TreeNode *p)
//{
//	TreeNode *q = p->right;
//
//	// ���� ������ ��ũ�� NULL�̰ų� p ��忡 thread�� �����ϸ�, ������ �����͸� ��ȯ
//	if (q == NULL || p->right_thread == true)
//		return q;
//
//	// ���� right child�� �����Ѵٸ�, �ٽ� ���� ���� ���� �̵�
//	while (q->left != NULL)
//		q = q->left;
//
//	return q;
//}
//
////���� ��ȸ
//void thread_inorder(TreeNode *t)
//{
//	TreeNode *q = t;
//
//	while (q->left != NULL)
//		q = q->left;
//
//	do {
//		cout << q->data << " "; // �湮�� ����� ������ ���
//		q = find_successor(q); // �ļ��� �Լ� ȣ��
//	} while (q);
//}
//
//int main()
//{
//	TreeNode n1 = { 'I', NULL, NULL, 1 };
//	TreeNode n2 = { 'H', NULL, NULL, 1 };
//	TreeNode n3 = { 'G', &n1, NULL, 0 };
//	TreeNode n4 = { 'F', NULL, NULL, 1 };
//	TreeNode n5 = { 'E', &n2, NULL, 1 };
//	TreeNode n6 = { 'D', NULL, NULL, 1 };
//	TreeNode n7 = { 'C', &n4, &n3, 0 };
//	TreeNode n8 = { 'B', &n6, &n5, 0 };
//	TreeNode n9 = { 'A', &n8, &n7, 0 };
//	TreeNode *exp = &n9;
//
//	// leaf node�� right thread (��, inorder successor) ����
//	n1.right = &n3; //I->G
//	n2.right = &n5; //H->E
//	n5.right = &n9; //E->A
//	n4.right = &n7; //F->C
//	n6.right = &n8; //D->B
//
//	// threaded binary tree���� ���� ��ȸ
//	thread_inorder(exp);
//	printf("\n");
//
//	return 0;
//}