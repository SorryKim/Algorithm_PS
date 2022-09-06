// baekjoon_1260
// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001] = { 0 };
bool visited[1001] = { false };

void BFS(int start, int size) {
	visited[start] = true;
	queue<int> q;
	q.push(start);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 1; i <= size; i++) {
			if (visited[i] == true || graph[v][i] == 0)
				continue;
			visited[i] = true;
			q.push(i);
		}
	}
}

void DFS(int start, int size) {
	visited[start] = true;
	cout << start << " ";

	for (int i = 1; i <= size; i++) {
		if (visited[i] == true || graph[start][i] == 0)
			continue;
		DFS(i, size);
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	DFS(v, n);
	fill_n(visited, 1001, false);
	cout << "\n";
	BFS(v, n);
}
