// baekjoon_2805 나무자르기
// https://www.acmicpc.net/problem/2805

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	long long sum = 0;
	int* array = new int[n];
	int result = 0;

	// 배열에 각각 나무 저장
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		array[i] = num;
	}

	// 이진 탐색사용 
	sort(array, array + n); // 이진탐색을 사용하기 위해 오름차순 정렬
	int left = 0;
	int right = array[n-1];

	while (right >= left) {
		int mid = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < n; i++) {
			if (array[i] > mid)
				sum += array[i] - mid;
		}
		if (sum >= m) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result;
}
