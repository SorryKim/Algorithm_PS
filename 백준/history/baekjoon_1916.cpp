// 최소비용 구하기 / baekjoon_1916.cpp
// https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
int N, M;
int start, destination;
vector<pair<int, int>> graph[1001];
int dist[1001]; // 거리값 저장할 배열

void Dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[now] < cost)
			continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_cost = graph[now][i].second + dist[now];

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next_cost,next });
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	cin >> start >> destination;
	for (int i = 0; i <= 1000; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;
	Dijkstra();

	cout << dist[destination];
}
