// N과 M (9) / baekjoon_15663.cpp
// https://www.acmicpc.net/problem/15663

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int N, M;
int arr[8] , temp[8];
bool visited[8] = { false, };

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

void DFS(int cnt) {
	
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << temp[i] << " ";
		cout << "\n";
		return;
	}

	int same = 0;
	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;

		if (same != arr[i]) {
			visited[i] = true;
			same = arr[i];
			temp[cnt] = arr[i];
			DFS(cnt + 1);
			visited[i] = false;
		}
	}
	
}

void Solve() {

	sort(arr, arr + N);
	DFS(0);

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
}
