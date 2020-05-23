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
//node* Alternate(node* head1, node* head2)
//{
//	node* temp1 = head1;
//	node* temp2 = head2;
//	node* result = NULL;
//
//	if (temp1 == NULL)
//	{
//		cout << "첫번째 리스트의 data가 없음" << endl;
//		exit(1);
//	}
//	if (temp2 == NULL)
//	{
//		cout << "두번째 리스트의 data가 없음" << endl;
//		exit(1);
//	}
//
//	while (true) {
//		if (temp1 != NULL) {
//			result = insert_sequence(result, temp1->data);
//			temp1 = temp1->next;
//		}
//		if (temp2 != NULL) {
//			result = insert_sequence(result, temp2->data);
//			temp2 = temp2->next;
//		}
//		if (temp1 == NULL && temp2 == NULL)
//			break;
//	}
//
//	return result;
//}
//
//int main()
//{
//	node *head1 = NULL;
//	node *head2 = NULL;
//	node *head3 = NULL;
//
//	cout << "리스트 1번" << endl;
//	head1 = insert_sequence(head1, 5);
//	head1 = insert_sequence(head1, 3);
//	head1 = insert_sequence(head1, 1);
//	print_list(head1);
//
//	cout << endl << "리스트 2번" << endl;
//	head2 = insert_sequence(head2, 8);
//	head2 = insert_sequence(head2, 7);
//	head2 = insert_sequence(head2, 6);
//	head2 = insert_sequence(head2, 4);
//	head2 = insert_sequence(head2, 2);
//	print_list(head2);
//
//	cout << endl << "리스트 alternate" << endl;
//	head3 = Alternate(head1, head2);
//	print_list(head3);
//
//	cout << endl << "시간 복잡도는 O(n)" << endl;
//	cout << "이유 : 첫번째 리스트의 값을 넣는데 n_1번, 2번째 리스트의 값을 넣는데 n_2번, " << endl
//		<< "총(n_1 + n_2)번 n_1 >= n_2 일 때 n_2 = n, n_1 = n+k (k = n_1-n_2)," << endl
//		<< "2n+k 이므로 3n >= 2n+k -> O(n)" << endl;
//
//	return 0;
//}