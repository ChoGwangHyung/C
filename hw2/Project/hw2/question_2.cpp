////������ �ڵ�
//#include <iostream>
//
//using namespace std;
//
//#define MAX_ELEMENT 200
//
//#pragma region Struct
//typedef struct treeNode
//{
//	int weight;
//	char ch;
//	struct treeNode *left;
//	struct treeNode *right;
//}TreeNode;
//
//typedef struct element
//{
//	TreeNode* ptree;
//	char ch;
//	int key;
//}Element;
//
//typedef struct heapType
//{
//	Element heap[MAX_ELEMENT];
//	int heap_size;
//}HeapType;
//#pragma endregion
//
//#pragma region Heap
////�� ���� �Լ�
//HeapType* create()
//{
//	HeapType* h = new HeapType;
//	h->heap_size = 0;
//	return h;
//}
//
//// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.(Heapify up)
//// ���� �Լ�
//void insert_min_heap(HeapType* h, Element item)
//{
//	int i = ++(h->heap_size);
//
//	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
//	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//
//	h->heap[i] = item; // ���ο� ��带 ����
//}
//
//// ������ �ּڰ� ���� �Լ�(Heapify down)
//Element delete_min_heap(HeapType* h)
//{
//	int parent = 1; //��Ʈ ��� �ε���
//	int child = 2; //��Ʈ �ڽ� ��� �ε���
//	Element item = h->heap[1]; //��Ʈ ��� element
//	Element temp = h->heap[(h->heap_size)--]; //���� ������ �ε����� ������ ���
//
//	while (child <= h->heap_size) {
//		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
//		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child +
//			1].key)
//			child++;
//
//		//������ �ε����� ������ ��尡 child�ε������� ������ break
//		if (temp.key <= h->heap[child].key)
//			break;
//
//		// �� �ܰ� �Ʒ��� �̵�
//		h->heap[parent] = h->heap[child];
//		parent = child;
//		child *= 2;
//	}
//
//	h->heap[parent] = temp;
//
//	return item;
//}
//#pragma endregion
//
//#pragma region Tree
//// ���� Ʈ�� ���� �Լ�
//TreeNode* make_tree(TreeNode* left, TreeNode* right)
//{
//	TreeNode* node = new TreeNode;
//	node->left = left;
//	node->right = right;
//
//	return node;
//}
//
//// ���� Ʈ�� ���� �Լ�
//void destroy_tree(TreeNode* root)
//{
//	if (root == NULL)
//		return;
//
//	destroy_tree(root->left);
//	destroy_tree(root->right);
//	delete root;
//
//	return;
//}
//
//int is_leaf(TreeNode* root)
//{
//	return !(root->left) && !(root->right);
//}
//#pragma endregion
//
//void print_array(int codes[], int n)
//{
//	for (int i = 0; i < n; i++)
//		printf("%d", codes[i]);
//
//	printf("\n");
//
//	return;
//}
//
//void print_codes(TreeNode* root, int codes[], int top)
//{
//	// 0�� �����ϰ� ��ȯȣ��
//	if (root->left)
//	{
//		codes[top] = 0;
//		print_codes(root->left, codes, top + 1);
//	}
//
//	// 1�� �����ϰ� ��ȯȣ��
//	if (root->right)
//	{
//		codes[top] = 1;
//		print_codes(root->right, codes, top + 1);
//	}
//
//	// �ܸ�����̸� �ڵ带 ���
//	if (is_leaf(root))
//	{
//		printf("%c: ", root->ch);
//		print_array(codes, top);
//	}
//
//	return;
//}
//
//// ������ �ڵ� ���� �Լ�
//void huffman_tree(int freq[], char ch_list[], int n)
//{
//	int i;
//	TreeNode *node, *x;
//	HeapType* heap;
//	Element e, e1, e2;
//	int codes[100];
//	int top = 0; //index of Huffman code array (������ �ڵ� Ʈ���� ����)
//
//	heap = create();
//
//	for (i = 0; i < n; i++)
//	{
//		node = make_tree(NULL, NULL);
//		e.ch = node->ch = ch_list[i];
//		e.key = node->weight = freq[i];
//		e.ptree = node;
//		insert_min_heap(heap, e);
//	}
//
//	for (i = 1; i < n; i++)
//	{
//		// �ּҰ��� ������ �ΰ��� ��带 ����
//		e1 = delete_min_heap(heap);
//		e2 = delete_min_heap(heap);
//		
//		// �ΰ��� ��带 ��ģ��.
//		x = make_tree(e1.ptree, e2.ptree);
//		e.key = x->weight = e1.key + e2.key;
//		e.ptree = x;
//		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
//		insert_min_heap(heap, e);
//	}
//
//	e = delete_min_heap(heap); // ���� Ʈ��
//	print_codes(e.ptree, codes, top);
//	destroy_tree(e.ptree);
//	delete heap;
//
//	return;
//}
//
//
//int main()
//{
//	char ch_list[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
//	int freq[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
//	huffman_tree(freq, ch_list, 8);
//
//	return 0;
//}