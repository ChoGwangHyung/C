////허프만 코드
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
////힙 생성 함수
//HeapType* create()
//{
//	HeapType* h = new HeapType;
//	h->heap_size = 0;
//	return h;
//}
//
//// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.(Heapify up)
//// 삽입 함수
//void insert_min_heap(HeapType* h, Element item)
//{
//	int i = ++(h->heap_size);
//
//	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
//	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//
//	h->heap[i] = item; // 새로운 노드를 삽입
//}
//
//// 힙에서 최솟값 삭제 함수(Heapify down)
//Element delete_min_heap(HeapType* h)
//{
//	int parent = 1; //루트 노드 인덱스
//	int child = 2; //루트 자식 노드 인덱스
//	Element item = h->heap[1]; //루트 노드 element
//	Element temp = h->heap[(h->heap_size)--]; //힙의 마지막 인덱스를 가지는 노드
//
//	while (child <= h->heap_size) {
//		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
//		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child +
//			1].key)
//			child++;
//
//		//마지막 인덱스를 가지는 노드가 child인덱스보다 작으면 break
//		if (temp.key <= h->heap[child].key)
//			break;
//
//		// 한 단계 아래로 이동
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
//// 이진 트리 생성 함수
//TreeNode* make_tree(TreeNode* left, TreeNode* right)
//{
//	TreeNode* node = new TreeNode;
//	node->left = left;
//	node->right = right;
//
//	return node;
//}
//
//// 이진 트리 제거 함수
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
//	// 0을 저장하고 순환호출
//	if (root->left)
//	{
//		codes[top] = 0;
//		print_codes(root->left, codes, top + 1);
//	}
//
//	// 1을 저장하고 순환호출
//	if (root->right)
//	{
//		codes[top] = 1;
//		print_codes(root->right, codes, top + 1);
//	}
//
//	// 단말노드이면 코드를 출력
//	if (is_leaf(root))
//	{
//		printf("%c: ", root->ch);
//		print_array(codes, top);
//	}
//
//	return;
//}
//
//// 허프만 코드 생성 함수
//void huffman_tree(int freq[], char ch_list[], int n)
//{
//	int i;
//	TreeNode *node, *x;
//	HeapType* heap;
//	Element e, e1, e2;
//	int codes[100];
//	int top = 0; //index of Huffman code array (허프만 코딩 트리의 레벨)
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
//		// 최소값을 가지는 두개의 노드를 삭제
//		e1 = delete_min_heap(heap);
//		e2 = delete_min_heap(heap);
//		
//		// 두개의 노드를 합친다.
//		x = make_tree(e1.ptree, e2.ptree);
//		e.key = x->weight = e1.key + e2.key;
//		e.ptree = x;
//		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
//		insert_min_heap(heap, e);
//	}
//
//	e = delete_min_heap(heap); // 최종 트리
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