// baekjoon_1927
// https://www.acmicpc.net/problem/1927

#include <iostream>
using namespace std;

class Heap {
private:
	int size;
	int* arr;
public:
	Heap(int n){
		this->size = 0;
		arr = new int[n + 1];
	}

	void insertHeap(int n) {
		int i = ++size;
		while (i != 1 && n < arr[i/2]) {
			arr[i] = arr[i / 2];
			i /= 2;
		}
		arr[i] = n;
	}

	int deleteHeap() {
		int parent, child;
		int item, temp;
		if (this->size == 0)
			return 0;
		item = arr[1];
		temp = arr[size--];
		parent = 1;
		child = 2;
		while (child <= size) {

			if ((child < size) && (arr[child] > arr[child + 1])) {
				child++;
			}
			if (temp <= arr[child])
				break;

			arr[parent] = arr[child];
			parent = child;
			child *= 2;
		}
		arr[parent] = temp;
		return item;
	}
};


int main() {
	int n;
	scanf("%d", &n);
	Heap heap = { n };

	for (int i = 0; i < n; i++) {

		int num;
		scanf("%d", &num);

		if (num == 0)
			printf("%d\n", heap.deleteHeap());
		else
			heap.insertHeap(num);
	}

}
