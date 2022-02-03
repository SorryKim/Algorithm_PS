// baekjoon_1654
// https://www.acmicpc.net/problem/1654
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int k = 0, n = 0;
	scanf("%d %d", &k, &n);
	int* array = new int[k];

	for (int i = 0; i < k; i++) {
		int num;
		scanf("%d", &num);
		array[i] = num;
	}
	sort(array, array+k);

	long long left = 1;
	long long right = array[k-1];
	long long sum = 0;
	long long result = 0;

	while (right >= left) {
		long long mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < k; i++) {
			sum += array[i] / mid;
		}
		if (sum >= n) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	printf("%d", result);
}
