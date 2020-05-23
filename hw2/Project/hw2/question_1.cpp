//#include <iostream>
//
//using namespace std;
//
//#define MAX_ELEMENT 200
//
//typedef struct element
//{
//	int key;
//	char task[100];
//} Element;
//
//typedef struct heapType
//{
//	Element heap[MAX_ELEMENT];
//	int heap_size;
//} HeapType;
//
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
//
////일의 우선순위에 따른 출력과 입력
//int main()
//{
//	HeapType* to_do_list = create();
//
//	char menu_key = 0;
//	Element item;
//
//	while (true)
//	{
//		cout << "Menu: Insert (i/I), Delete (d/D), Quit(q/Q) : ";
//		cin >> menu_key;
//		cout << "===========================" << endl;
//
//		switch (menu_key)
//		{
//			//i,I 입력 - 삽입
//		case 'i':
//		case 'I':
//			cout << "To do : ";
//			cin.get();
//			cin.getline(item.task, 100, '\n');
//			cout << "Precedence : ";
//			cin >> item.key;
//			printf("Precedence %d, \"%s\" is inserted.\n", item.key, item.task);
//			insert_min_heap(to_do_list, item);
//			break;
//			//d,D 입력 - 삭제
//		case 'd':
//		case 'D':
//			item = delete_min_heap(to_do_list);
//			cout << "To do : " << item.task << endl;
//			cout << "Precedence : " << item.key << endl;
//			printf("Precedence %d, \"%s\" is deleted.\n", item.key, item.task);
//			break;
//			//q,Q 입력 - 종료
//		case 'q':
//		case 'Q':
//			cout << "Bye" << endl;
//			return 0;
//		}
//		cout << endl;
//	}
//
//	delete to_do_list;
//
//	return 0;
//}