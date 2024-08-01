#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
int dist[1001];
vector<pair<int, int>> graph[1001];

void Dijkstra(int start) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[now] < cost)
			continue;

		for (auto a : graph[now]) {

			int next = a.first;
			int next_cost = a.second + dist[now];

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

	int N, M;
	cin >> N >> M;
	

	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end,cost });
	}

	for (int i = 0; i <= N; i++)
		dist[i] = INF;
	
	int start, end;
	cin >> start >> end;
	Dijkstra(start);

	cout << dist[end] << '\n';
}