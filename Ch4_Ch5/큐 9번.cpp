//#include <iostream>
//
//using namespace std;
//
//const int MAXSIZE = 20;
//
//typedef struct Stack {
//	int last;
//	int data[MAXSIZE];
//}S;
//
//typedef struct Queue {
//	S A;
//	S B;
//}Q;
//
//
//#pragma region stack함수
//bool IsEmpty(S& stack)
//{
//	if (stack.last == -1)return true;
//	else return false;
//}
//
//bool IsFull(S& stack)
//{
//	if (stack.last == MAXSIZE - 1)return true;
//	else return false;
//}
//
//void Initialize(S& stack)
//{
//	stack.last = -1;
//}
//
//int Pop(S& stack)
//{
//	if (IsEmpty(stack)) {
//		cout << "Is Empty" << endl;
//		exit(1);
//	}
//	else return stack.data[stack.last--];
//
//}
//
//int Push(S& stack, int x)
//{
//	if (IsFull(stack)) {
//		cout << "Is Full" << endl;
//		exit(1);
//	}
//
//	stack.data[++stack.last] = x;
//
//	return stack.data[stack.last];
//}
//
//int Top(S& stack)
//{
//	if (IsEmpty(stack)) {
//		cout << "Is Empty" << endl;
//		exit(1);
//	}
//
//	else return stack.data[stack.last];
//}
//
//int Size(S& stack)
//{
//	return stack.last + 1;
//}
//#pragma endregion
//
//#pragma region Queue 함수
//void InitializeQ(Q& queue) {
//	Initialize(queue.A);
//	Initialize(queue.B);
//}
//
//int IsQEmpty(Q& queue) {
//	if (queue.A.last == -1 && queue.B.last == -1)
//		return true;
//	else
//		return false;
//}
//
//int IsQFull(Q& queue) {
//
//	if (IsFull(queue.A) || IsFull(queue.B))
//		return true;
//	else
//		return false;
//}
//
//void Enqueue(Q& queue, int x) {
//	if (IsQFull(queue)) {
//		printf("Queue is full!\n");
//		exit(1);
//	}
//
//	else {
//		if (IsEmpty(queue.A) && !IsEmpty(queue.B))
//		{
//			while (!IsEmpty(queue.B))
//				Push(queue.A, Pop(queue.B));
//		}
//		Push(queue.A, x);
//		printf("Insert %d\n", x);
//	}
//}
//
//int Dequeue(Q& queue) {
//	if (IsQEmpty(queue)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	if (IsEmpty(queue.B)) {
//		while(!IsEmpty(queue.A))
//			Push(queue.B, Pop(queue.A));
//	}
//
//	return Pop(queue.B);
//}
//
//int Peek(Q& queue) {
//
//	if (IsQEmpty(queue)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	return (Top(queue.B));
//}
//
//void PrintQ(Q& queue) {
//
//	if (IsQEmpty(queue)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	if (!IsEmpty(queue.A))
//		while (!IsEmpty(queue.A))
//			Push(queue.B, Pop(queue.A));
//
//	for (int i = Size(queue.B) - 1; i > -1; i--)
//		printf("%d ", queue.B.data[i]);
//
//	printf("\n");
//}
//
//int CountQ(Q& queue) {
//
//	int num = 0;
//
//	if (IsQEmpty(queue)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	for (int i = 0; i < Size(queue.B); i++)
//		num++;
//
//	return num;
//}
//#pragma endregion
//
//
//
//
//int main()
//{
//	Q test;
//
//	InitializeQ(test);
//
//	Enqueue(test, 1);
//	Enqueue(test, 2);
//	Enqueue(test, 3);
//	Enqueue(test, 4);
//
//	printf("Bring out %d\n", Dequeue(test));
//	printf("Bring out %d\n", Dequeue(test));
//
//	Enqueue(test, 5);
//	Enqueue(test, 6);
//
//	printf("Bring out %d\n", Dequeue(test));
//	printf("Bring out %d\n", Dequeue(test));
//	printf("Bring out %d\n", Dequeue(test));
//	printf("Bring out %d\n", Dequeue(test));
//
//
//	return 0;
//}