// N과 M (3) / baekjoon_15651.cpp
// https://www.acmicpc.net/problem/15651

#include <iostream>
using namespace std;

int N, M;
bool visited[8] = { false, };
int arr[8] = { 0, };

void DFS(int n) {
	
	// 선택 완료
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	else {
		for (int i = 1; i <= N; i++) {
			visited[i] = true;
			arr[n] = i;
			DFS(n + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	DFS(0);
}