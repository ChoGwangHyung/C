#include <iostream>
#include <time.h>

using namespace std;

int qsort_val = 0;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_arr(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		if (i % 10 == 9)cout << endl;
	}
	cout << "quicksort는 총 " << qsort_val << "번 호출 되었습니다."<<endl;
	return;
}

int partition(int data[], int low, int high) {
	int pivot = data[high];
	int pIndex = low;

	for (int i = low; i < high; i++) {
		if (data[i] < pivot) {
			swap(&data[i], &data[pIndex]);			
			pIndex++;
		}
	}
	swap(&data[pIndex], &data[high]);	
	return pIndex;
}

void quicksort(int data[], int low, int high) {
		
	if (low < high) {		
		qsort_val++;

		int pIndex = partition(data, low, high);
		quicksort(data, low, pIndex - 1);	
		quicksort(data, pIndex + 1, high);
	}
}


int main()
{
	int arr[100];

	srand(time(NULL));
	
	for (int i = 0; i < 100; i++)
		arr[i] = rand() % 100;

	print_arr(arr, 100);
	quicksort(arr, 0, 99);	
	print_arr(arr, 100);

}