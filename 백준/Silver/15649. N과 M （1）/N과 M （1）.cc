// N과 M (1) / baekjoon_15649.cpp
// https://www.acmicpc.net/problem/15649

#include <iostream>
using namespace std;

int N, M;
int arr[9] = { 0, };
bool visited[9] = { false, };

void DFS(int n) {

	// 재귀 종료시점
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	// N개의 원소를 구하는 과정
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[n] = i;
			DFS(n + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	DFS(0);
}