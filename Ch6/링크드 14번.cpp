//#include <iostream>
//
//using namespace std;
//
//typedef struct Information {
//	char name[10];
//	int age;
//	float heigh;
//}info;
//
//typedef struct Node {
//	info data;
//	Node* next;
//}node;
//
//
//node* create(info x)
//{
//	node* temp;
//
//	temp = (node*)malloc(sizeof(node));
//
//	if (temp == NULL)
//		return NULL;
//
//	else {
//		temp->data = x;
//		temp->next = NULL;
//		return temp;
//	}
//}
//
//node* insert_sequence(node* head, info x)
//{
//	node* temp = create(x);
//
//	if (temp == NULL)
//	{
//		cout << "할당 실패" << endl;
//		return NULL;
//	}
//
//	temp->next = head;
//
//	head = temp;
//
//	return head;
//}
//
//node* insert_between(node* head, node* pre, info x)
//{
//	node* temp = create(x);
//
//	if (temp == NULL)
//	{
//		cout << "할당 실패" << endl;
//		return NULL;
//	}
//
//	temp->next = pre->next;
//
//	pre->next = temp;
//
//	return head;
//}
//
//node* search(node* head, info key)
//{
//	bool findKey = false;
//
//	node* temp = head;
//
//	while (!findKey && temp != NULL) {
//		if (temp->data.name == key.name&&temp->data.age == key.age&&temp->data.heigh == key.heigh) {
//			findKey = true;
//			break;
//		}
//		else
//			temp = temp->next;
//	}
//
//	if (findKey)
//		return temp;
//	else {
//		cout << "찾지 못함" << endl;
//		return NULL;
//	}
//}
//
//node* remove_sequence(node* head)
//{
//	node* temp = head;
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		return NULL;
//	}
//
//	head = temp->next;
//
//	free(temp);
//
//	return head;
//}
//
//node* remove_between(node* head, node* pre)
//{
//	node* temp;
//
//	if (head == NULL || pre == NULL)
//	{
//		cout << "data가 없음" << endl;
//		return NULL;
//	}
//
//	temp = pre->next;
//
//	pre->next = pre->next->next;
//
//	free(temp);
//
//	return head;
//}
//
//void print_list(node* head)
//{
//	node* temp = head;
//	int num = 1;
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		return;
//	}
//
//	while (temp != NULL) {
//		cout << fixed;
//		cout.precision(1);
//
//		cout << num << "번째 데이터" << endl;
//		cout << "Name : " << temp->data.name << endl;
//		cout << "Age : " << temp->data.age << endl;
//		cout << "Heigh : " << temp->data.heigh << endl << endl;
//		temp = temp->next;
//		num++;
//	}
//	cout << "NULL" << endl;
//}
//
//int size(node* head)
//{
//	int size_value = 0;
//	node* temp = head;
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		return size_value;
//	}
//
//	while (temp != NULL) {
//		size_value++;
//		temp = temp->next;
//	}
//
//	return size_value;
//}
//
//int main()
//{
//	node *head = NULL;
//
//	info data[4] = {
//	{"choi",30,1.3},
//	{"lee",48,1.4},
//	{"park",27,1.2},
//	{"kie",34,1.7} };
//
//	for (int i = 0; i < 4; i++)
//		head = insert_sequence(head, data[i]);
//
//	print_list(head);
//
//	return 0;
//}