#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node *llink;
	struct	node *rlink;
}DNode;

DNode* Create(int x)
{
	DNode *temp = NULL;
	temp = (DNode*)malloc(sizeof(DNode));

	if (temp == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return NULL;
	}

	else {
		temp->data = x;
		temp->llink = NULL;
		temp->rlink = NULL;
	}

	return temp;
}

void Insert(DNode *head, int x) {
	DNode *temp = NULL;

	temp = Create(x);

	if (temp == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return;
	}

	else {
		//ó�� ����
		if (head->rlink == NULL) {
			head->rlink = temp;
			temp->llink = head;
		}
		else {
			//����� ������ ���� ����
			while (head->rlink != NULL)head = head->rlink;
			head->rlink = temp;
			temp->llink = head;
		}

	}
}

DNode* search(DNode *head, int key) {
	int seq = 1;
	DNode *temp = head;

	while (temp != NULL) {
		if (temp->data == key) {
			cout <<  seq << " ��° ��忡�� key ���� ã�ҽ��ϴ�." <<  endl;
			return temp;
		}
		temp = temp->rlink;
		seq++;
	}

	//�� ã���� ��
	cout << "key ���� ã�� ���߽��ϴ�." << endl;

	return NULL;
}

void print_node(DNode *head) {
	DNode *temp = head;

	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->rlink;
	}
	cout << "NULL" << endl;
}

int main() {

	DNode *head = Create(1);
	DNode *search_node;
	Insert(head, 4);
	Insert(head, 3);
	Insert(head, 2);

	print_node(head);

	cout << "key�� �� : 3" << endl;

	search_node = search(head, 3);


	return 0;
}
