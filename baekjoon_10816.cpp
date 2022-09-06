// baekjoon_10816
// https://www.acmicpc.net/problem/10816

#include <iostream>
#include <algorithm>
using namespace std;

int check_low(int* arr, int num, int n) {
	int count = 0;
	int left = 0;
	int right = n - 1;
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] >= num) {
			if (arr[mid] == num)
				result = mid;
			right = mid - 1;
		}
		else if(arr[mid] < num)
			left = mid + 1;
	}

	return result;
}

int check_high(int* arr, int num, int n) {
	int count = 0;
	int left = 0;
	int right = n - 1;
	int result = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] > num)
			right = mid - 1;
		else if (arr[mid] <= num) {
			if (arr[mid] == num)
				result = mid;
			left = mid + 1;
		}
	}

	return result;
}

int main() {
	int n;
	scanf("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		arr[i] = m;
	}
	sort(arr, arr + n);
	
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		int low = check_low(arr, num, n);
		int high = check_high(arr, num, n);
		if (low == -1) {
			cout << 0 << " ";
		}
		else if (low == high) {
			cout << 1 << " ";
		}
		else {
			cout << high - low + 1 << " ";
		}
	}
}
