// 결혼식 / baekjoon_5567.cpp
// https://www.acmicpc.net/problem/5567

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
bool graph[501][501];
bool result[501];

void Input() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

}

void DFS(int now, int depth) {

	if (depth == 2)
		return;

	for (int i = 1; i <= n; i++) {

		if (graph[now][i]) {
			result[i] = true;
			DFS(i, depth + 1);
		}
			
	}
}

void Solve() {


	result[1] = true;
	DFS(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (result[i])
			ans++;
	}

	cout << ans - 1;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
