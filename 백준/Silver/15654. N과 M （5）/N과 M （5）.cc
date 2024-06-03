// N과 M (5) / baekjoon_15654.cpp
// https://www.acmicpc.net/problem/15654

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int result[9] = { 0, };
int arr[9] = { 0, };
bool visited[9] = { false, };

void DFS(int n) {

	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {

		if (visited[i] == true)
			continue;
		visited[i] = true;
		result[n] = arr[i];
		DFS(n + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < 9; i++) {
		arr[i] = 987654321;
	}

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 9);

	DFS(0);
}