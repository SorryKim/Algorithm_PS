// 플로이드 / baekjoon_11404.cpp
// https://www.acmicpc.net/problem/11404

#include <iostream>
using namespace std;

int n, m;
int graph[101][101];
#define MAX 10000000

// 시간복잡도 O(n^3) 플로이드 - 와샬
void floyd_warshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (graph[j][i] != MAX && graph[i][k] != MAX) {
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		int start, destination, cost;
		cin >> start >> destination >> cost;
		if (graph[start][destination] > cost)
			graph[start][destination] = cost;
	}

	floyd_warshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == MAX || i == j)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	
}
