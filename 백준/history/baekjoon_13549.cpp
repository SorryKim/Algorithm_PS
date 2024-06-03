// 숨바꼭질 3 / baekjoon_13549.cpp
// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>
using namespace std;

int N, K;
int arr[100001];
queue<int> q;

int BFS(int n) {
	q.push(n);
	arr[n] = 0;

	while (!q.empty()) {
		int i = q.front();
		q.pop();

		if (i == K) {
			return arr[i];
		}

		// 순간이동은 0초 걸림, 우선적으로 해줌
		if (i * 2 <= 100000 && arr[i * 2] > arr[i]) {
			q.push(i * 2);
			arr[i * 2] = arr[i];
		}

		if (i + 1 <= 100000 && arr[i + 1] > arr[i] + 1) {
			q.push(i + 1);
			arr[i + 1] = arr[i] + 1;
		}

		if (i - 1 >= 0 && arr[i - 1] > arr[i] + 1) {
			q.push(i - 1);
			arr[i - 1] = arr[i] + 1;
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;

	// 배열을 큰값으로 채워넣어 최솟값으로 작동하게 함
	for (int i = 0; i <= 100000; i++) {
		arr[i] = 12345678;
	}

	cout << BFS(N);

	return 0;
}
