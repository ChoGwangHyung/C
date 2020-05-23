//#include <iostream>
//
//using namespace std;
//
//int const MAXSIZE = 20;
//
//typedef struct Queue {
//	int front;
//	int rear;
//	int A[MAXSIZE];
//}Q;
//
//void InitializeQ(Q& test) {
//
//	test.front = -1;
//	test.rear = -1;
//}
//
//int IsQEmpty(Q& test) {
//
//	if (test.front == -1 && test.rear == -1)
//		return true;
//	else
//		return false;
//}
//
//int IsQFull(Q& test) {
//
//	if ((test.rear + 1) % MAXSIZE == test.front)
//		return true;
//	else
//		return false;
//}
//
//void Enqueue(Q& test, int x) {
//	if (IsQFull(test)) {
//		printf("Is full!\n");
//		exit(1);
//	}
//
//	if (IsQEmpty(test)) {
//		test.front = 0;
//		test.rear = 0;
//		test.A[test.rear] = x;
//	}
//
//	else {
//		test.rear = (test.rear + 1) % MAXSIZE;
//		test.A[test.rear] = x;
//	}
//}
//
//int Dequeue(Q& test) {
//	int temp;
//
//	if (IsQEmpty(test)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	temp = test.A[test.front];
//
//	if (test.front == test.rear) {
//		test.front = -1;
//		test.rear = -1;
//	}
//	else
//		test.front = (test.front + 1) % MAXSIZE;
//
//	return temp;
//}
//
//int Peek(Q& test) {
//
//	if (IsQEmpty(test)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	return (test.A[test.front]);
//}
//
//void PrintQ(Q& test) {
//
//	if (IsQEmpty(test)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	if (test.front <= test.rear) {
//		for (int i = test.front; i <= test.rear; i++)
//			printf("%d ", test.A[i]);
//	}
//
//	else {
//		for (int i = test.front; i <= test.rear + MAXSIZE; i++)
//			printf("%d ", test.A[i%MAXSIZE]);
//	}
//	printf("\n");
//}
//
//int CountQ(Q& test) {
//	
//	int num = 0;
//
//	if (IsQEmpty(test)) {
//		printf("Is empty!\n");
//		exit(1);
//	}
//
//	if (test.front <= test.rear) {
//		for (int i = test.front; i <= test.rear; i++)
//			num++;
//	}
//
//	else {
//		for (int i = test.front; i <= test.rear + MAXSIZE; i++)
//			num++;
//	}
//
//	return num;
//}
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
//	printf("큐에 존재하는 요소의 개수 : %d개\n", CountQ(test));
//
//	return 0;
//}