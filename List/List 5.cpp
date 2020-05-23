#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}BTNode;

BTNode *create_node(int x) {
	BTNode *temp = NULL;

	temp = (BTNode*)malloc(sizeof(BTNode));
	if (temp == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return NULL;
	}
	else {
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
	}

	return temp;
}

BTNode *insert(BTNode *root, int x) {
	BTNode *temp = NULL;
	temp = create_node(x);

	if (root == NULL) {
		root = temp;
		return root;
	}

	if (x <= root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);

	return root;
}

void print_inorder(BTNode *root) {

	if (root == NULL)
		return;

	print_inorder(root->left);
	cout << root->data << " ";
	print_inorder(root->right);

	return;
}


void print_preorder(BTNode *root) {

	if (root == NULL)
		return;

	printf("%d ", root->data);
	print_preorder(root->left);
	print_preorder(root->right);

	return;
}

void print_postorder(BTNode *root) {

	if (root == NULL)
		return;

	print_postorder(root->left);
	print_postorder(root->right);
	printf("%d ", root->data);

	return;
}

int max(int x, int y) {
	//x�� y���� ũ�ų� ������ x��ȯ
	//y�� x���� ũ�� y��ȯ
	return ((x >= y) ? x : y);
}

int find_height(BTNode* root) {

	if (root == NULL)
		return -1;

	return (1 + max(find_height(root->left), find_height(root->right)));
}

int is_balanced(BTNode *root) {
	int leftHeight = find_height(root->left);
	int rightHeight = find_height(root->right);

	if ((leftHeight >= rightHeight + 1 && leftHeight <= rightHeight - 1) ||
		(leftHeight + 1 >= rightHeight && leftHeight - 1 <= rightHeight))
		return 1;
	else return 0;
}

int main()
{
	BTNode *root = NULL;

	root = create_node(10);

	insert(root, 5);
	insert(root, 15);
	insert(root, 3);
	insert(root, 6);
	insert(root, 17);
	insert(root, 13);
	insert(root, 20);
	insert(root, 25);

	print_preorder(root);

	cout << endl;
	cout << "Ʈ���� ���� : " << find_height(root) << endl;
	cout << "���� Ʈ���ΰ� : ";
	if (is_balanced(root)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}