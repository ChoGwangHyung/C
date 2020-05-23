//#include <iostream>
//
//using namespace std;
//
//typedef struct Node {
//	int data;
//	Node* next;
//}node;
//
//
//node* create(int x)
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
//node* insert_sequence(node* head, int x)
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
//node* insert_between(node* head, node* pre, int x)
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
//node* search(node* head, int key)
//{
//	bool findKey = false;
//
//	node* temp = head;
//
//	while (!findKey && temp != NULL) {
//		if (temp->data == key) {
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
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		return;
//	}
//
//	while (temp != NULL) {
//		cout << temp->data << " >> ";
//		temp = temp->next;
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
//int sum_data(node* head)
//{
//	int sum_value = 0;
//	node* temp = head;
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		exit(1);
//	}
//
//	while (temp != NULL) {
//		sum_value += temp->data;
//		temp = temp->next;
//	}
//
//	return sum_value;
//}
//
//int search_num(node* head, int num_data)
//{
//	int num_value = 0;
//	node* temp = head;
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		exit(1);
//	}
//
//	while (temp != NULL) {
//		if (temp->data == num_data) {
//			num_value++;
//		}
//		temp = temp->next;
//	}
//
//	return num_value;
//}
//
//int search_maxValue(node* head)
//{
//	node* temp = head;
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		exit(1);
//	}
//
//	int max_value = temp->data;
//
//	while (temp != NULL) {
//		if (temp->data > max_value) {
//			max_value = temp->data;
//		}
//		temp = temp->next;
//	}
//
//	return max_value;
//}
//
//int search_minValue(node* head)
//{
//	node* temp = head;
//
//	if (temp == NULL)
//	{
//		cout << "data가 없음" << endl;
//		exit(1);
//	}
//
//	int min_value = temp->data;
//
//
//	while (temp != NULL) {
//		if (temp->data < min_value) {
//			min_value = temp->data;
//		}
//		temp = temp->next;
//	}
//
//	return min_value;
//}
//
//int main()
//{
//	node *head = NULL;
//
//	head = insert_sequence(head, 2);
//	head = insert_sequence(head, 5);
//	head = insert_sequence(head, 10);
//	head = insert_sequence(head, 7);
//	head = insert_sequence(head, 4);
//	print_list(head);	
//
//	cout << "최대값 : " << search_maxValue(head) << endl;
//	cout << "최소값 : " << search_minValue(head) << endl;
//
//	return 0;
//}