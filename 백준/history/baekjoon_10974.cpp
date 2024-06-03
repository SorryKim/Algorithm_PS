// 모든 순열 / baekjoon_10974.cpp
// https://www.acmicpc.net/problem/10974

#include <iostream>
using namespace std;

int arr[9];
int N;
int result[9];
bool visited[9] = { false, };

void DFS(int n) {

	if (n == N + 1) {
		for (int i = 1; i <= N; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == true)
			continue;
		visited[i] = true;
		result[n] = i;
		DFS(n + 1);
		visited[i] = false;
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i <= 8; i++)
		arr[i] = i;

	DFS(1);
}
