// N과 M (4) / baekjoon_15652.cpp
// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool visited[9] = { false, };
int arr[9], result[9];


void DFS(int n, int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	else {
		for (int i = n; i <= N; i++) {
			visited[i] = true;
			result[cnt] = i;
			DFS(i, cnt + 1);
			visited[i] = false;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < 9; i++)
		arr[i] = i;

	DFS(1, 0);

}
