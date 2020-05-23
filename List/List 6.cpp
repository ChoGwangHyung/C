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
		cout << "메모리 할당 실패" << endl;
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
	//x가 y보다 크거나 같으면 x반환
	//y가 x보다 크면 y반환
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

	cout << "left : " << leftHeight << endl;
	cout << "right : " << rightHeight << endl;

	if ((leftHeight >= rightHeight + 1 && leftHeight <= rightHeight - 1) ||
		(leftHeight + 1 >= rightHeight && leftHeight - 1 <= rightHeight))
		return 1;
	else return 0;
}

int sum(BTNode* root) {
	int sum_val;

	if (root == NULL)
		return 0;
	else {
		sum_val = root->data;
		sum_val += sum(root->right) + sum(root->left);
		return sum_val;
	}		
}

int main()
{
	BTNode *root = NULL;

	root = create_node(5);

	insert(root, 4);
	insert(root, 1);
	insert(root, 2);
	insert(root, 3);
	insert(root, 6);
	insert(root, 9);
	insert(root, 7);
	insert(root, 8);

	print_preorder(root);

	cout << endl;
	cout << "트리의 모든 노드의 합 : " << sum(root) << endl;

	return 0;
}