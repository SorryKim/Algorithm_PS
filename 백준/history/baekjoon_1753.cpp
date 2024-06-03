// 최단경로 / baekjoon_1753.cpp
// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001];

void Dijkstra() {
	// min heap사용
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // { 가중치, 목적지 } 쌍
	pq.push({ 0,K });
	dist[K] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost)
			continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			// 더 작은값이면 값 갱신
			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push({ dist[next],next });
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v,w));
	}

	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	Dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}

