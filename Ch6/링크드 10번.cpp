#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	Node* next;
}node;


node* create(int x)
{
	node* temp;

	temp = (node*)malloc(sizeof(node));

	if (temp == NULL)
		return NULL;

	else {
		temp->data = x;
		temp->next = NULL;
		return temp;
	}
}

node* insert_sequence(node* head, int x)
{
	node* temp = create(x);

	if (temp == NULL)
	{
		cout << "할당 실패" << endl;
		return NULL;
	}

	temp->next = head;

	head = temp;

	return head;
}

node* insert_between(node* head, node* pre, int x)
{
	node* temp = create(x);

	if (temp == NULL)
	{
		cout << "할당 실패" << endl;
		return NULL;
	}

	temp->next = pre->next;

	pre->next = temp;

	return head;
}

node* search(node* head, int key)
{
	bool findKey = false;

	node* temp = head;

	while (!findKey && temp != NULL) {
		if (temp->data == key) {
			findKey = true;
			break;
		}
		else
			temp = temp->next;
	}

	if (findKey)
		return temp;
	else {
		cout << "찾지 못함" << endl;
		return NULL;
	}
}

node* remove_sequence(node* head)
{
	node* temp = head;

	if (temp == NULL)
	{
		cout << "data가 없음" << endl;
		return NULL;
	}

	head = temp->next;

	free(temp);

	return head;
}

node* remove_between(node* head, node* pre)
{
	node* temp;

	if (head == NULL || pre == NULL)
	{
		cout << "data가 없음" << endl;
		return NULL;
	}

	temp = pre->next;

	pre->next = pre->next->next;

	free(temp);

	return head;
}

void print_list(node* head)
{
	node* temp = head;

	if (temp == NULL)
	{
		cout << "data가 없음" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->data << " >> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int size(node* head)
{
	int size_value = 0;
	node* temp = head;

	if (temp == NULL)
	{
		return size_value;
	}

	while (temp != NULL) {
		size_value++;
		temp = temp->next;
	}

	return size_value;
}


int main()
{
	Node *head = NULL;

	head = insert_sequence(head, 5);
	head = insert_sequence(head, 6);
	head = insert_sequence(head, 7);
	print_list(head);

	cout << "노드의 개수 : " << size(head) << endl;


	return 0;
}