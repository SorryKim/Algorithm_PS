// 노드사이의 거리 / baekjoon_1240.cpp
// https://www.acmicpc.net/problem/1240

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector <pair<int, int>> tree[1001];
int dist[1001] = { 0, };

int BFS(int start, int end) {
	queue<int> q;
	q.push(start);

	for (int i = 1; i <= 1000; i++)
		dist[i] = -1;

	dist[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto next : tree[now]) {
			if (dist[next.first] == -1) {
				dist[next.first] = dist[now] + next.second;
				q.push(next.first);
			}
			else
				continue;
		}
		
	}
	return dist[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		tree[start].push_back({ end,cost });
		tree[end].push_back({ start,cost });
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		cout << BFS(start,end) << "\n";
	}
}
