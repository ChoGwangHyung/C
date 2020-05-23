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
//// 노드 p의 중위 후속자 (inorder successor) 찾기
//TreeNode *find_successor(TreeNode *p)
//{
//	TreeNode *q = p->right;
//
//	// 만약 오른쪽 링크가 NULL이거나 p 노드에 thread가 존재하면, 오른쪽 포인터를 반환
//	if (q == NULL || p->right_thread == true)
//		return q;
//
//	// 만약 right child가 존재한다면, 다시 가장 왼쪽 노드로 이동
//	while (q->left != NULL)
//		q = q->left;
//
//	return q;
//}
//
////중위 순회
//void thread_inorder(TreeNode *t)
//{
//	TreeNode *q = t;
//
//	while (q->left != NULL)
//		q = q->left;
//
//	do {
//		cout << q->data << " "; // 방문한 노드의 데이터 출력
//		q = find_successor(q); // 후속자 함수 호출
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
//	// leaf node의 right thread (즉, inorder successor) 설정
//	n1.right = &n3; //I->G
//	n2.right = &n5; //H->E
//	n5.right = &n9; //E->A
//	n4.right = &n7; //F->C
//	n6.right = &n8; //D->B
//
//	// threaded binary tree에서 중위 순회
//	thread_inorder(exp);
//	printf("\n");
//
//	return 0;
//}