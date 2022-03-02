// baekjoon_11724
// https://www.acmicpc.net/problem/11724
#include <iostream>
using namespace std;

int graph[1001][1001] = { 0, };
bool check[1001] = { false, };

void DFS(int v) {
	check[v] = true;
	for (int i = 1; i <= 1000; i++) {
		if ((graph[v][i] == 1) && (check[i] == false)) {
			DFS(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
		
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			result++;
			DFS(i);
		}
	}

	cout << result;

}
