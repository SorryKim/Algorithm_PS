// baekjoon_1920
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int binarySearch(int array[], int left, int right, int key) {
	int mid;
	while (right >= left) {
		mid = (left + right) / 2;
		if (array[mid] == key)
			return 1;
		else if (array[mid] > key) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return 0;
}

int main() {
	int n,m;
	scanf("%d", &n);
	int* array = new int[n];

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		array[i] = num;
	}
	sort(array, array + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		printf("%d\n", binarySearch(array, 0, n - 1, num));
	}

	delete array;
}
