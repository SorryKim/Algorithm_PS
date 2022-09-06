// baekjoon_1697
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
using namespace std;

int arr[100001] = { 0 };
queue<int> q;

int BFS(int n,int k){
	q.push(n);
	arr[n] = 1;

	while (!q.empty()) {
		int i = q.front();
		q.pop();

		if (i == k) {
			int result = arr[i] - 1;
			return result;
		}
		if (i - 1 >= 0 && arr[i - 1] == 0) {
			q.push(i - 1);
			arr[i - 1] = arr[i] + 1;
		}
		if (i + 1 <= 100000 && arr[i + 1] == 0) {
			q.push(i + 1);
			arr[i + 1] = arr[i] + 1;
		}
		if (i * 2 <= 100000 && arr[i * 2] == 0) {
			q.push(i * 2);
			arr[i * 2] = arr[i] + 1;
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	cout << BFS(N, K);
}
