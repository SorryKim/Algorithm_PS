// 절댓값 힙 / baekjoon_11286
// https://www.acmicpc.net/problem/11286

#include <iostream>
#include <cstdlib>

using namespace std;

// 절댓값 힙
class Heap {
private:
	int size;
	int* arr;

public:
	// 생성자
	Heap() {}
	Heap(int n) {
		this->size = 0;
		arr = new int[n + 1]; // 1 ~ n까지 사용, 0은 혼란을 피해 사용하지 않을 예정
	}

	// 원소 추가 메소드
	void add(int n) {
		int i = ++size;
		while (i != 1 && abs(n) <= abs(arr[i / 2])) {
			arr[i] = arr[i / 2];
			if (abs(n) == abs(arr[i / 2])) {
				if (n < arr[i / 2]) {
					break;
				}
			}
			i /= 2;
		}
		arr[i] = n;
	}


	// 원소 삭제 메소드
	int pop() {
		int result = arr[1];
		int parent, child;
		if (this->size == 0)
			return 0;
		int temp = arr[size--];
		parent = 1;
		child = 2;
		while (child <= this->size) {
			if ((child < size) && abs(arr[child]) > abs(arr[child + 1]))
				child++;

			if (abs(temp) < arr[child])
				break;

			else if (abs(temp) == abs(arr[child])) {
				if (temp < arr[child])
					break;
			}

			arr[parent] = arr[child];
			parent = child;
			child *= 2;
		}
		arr[parent] = temp;
		return result;
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	Heap heap = { N };

	while (N--) {
		int n;
		cin >> n;
		if (n == 0) {
			cout << heap.pop() << "\n";
		}
		else {
			heap.add(n);
		}
	}
}
