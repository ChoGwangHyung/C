#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node *link;
}Node;

Node *create_node(int x) {
	Node *temp = NULL;

	temp = (Node*)malloc(sizeof(Node));

	if (temp == NULL) {
		cout << "메모리 할당 실패" << endl;
		return NULL;
	}

	else {
		temp->data = x;
		temp->link = NULL;
		return temp;
	}
}

void  insert_last(Node* head, int x) {
	Node * temp = NULL;

	temp = create_node(x);

	if (temp == NULL) {
		cout << "메모리 할당 실패" << endl;
		return;
	}

	else {
		//헤드를 제외한 데이터가 없을 때
		if (head->link == NULL) {
			head->link = temp;
			temp->link = head;
		}
		//헤드를 제외한 데이터가 있을 때
		else {
			temp->link = head->link;
			head->link = temp;			
		}
	}	
}

//역순 출력
void print_node(Node* head) {

	Node* temp = head->link;

	while (temp != head) {
		cout << temp->data << " ";
		temp = temp->link;
	}

	cout << temp->data << endl;
}

int get_size(Node* p) {
	int num = 0;
	Node* temp = p->link;

	while (temp != p) {
		num++;
		temp = temp->link;
	}
	//head->data
	num++;

	return num;
}

int main()
{
	Node* head = create_node(1);

	insert_last(head, 2);
	insert_last(head, 3);
	insert_last(head, 4);

	print_node(head);

	cout << "노드의 개수 : " << get_size(head) << endl;

	return 0;
}