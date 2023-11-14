#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321

struct Edge {
	int end, cost;

	Edge(int end, int cost) {
		
		this->end = end;
		this->cost = cost;
	}
	bool operator()(Edge& a, Edge& b) {
		return a.cost > b.cost;
	}

};

struct Compare {
	bool operator()(Edge& a, Edge& b) {
		return a.cost > b.cost;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test = 1; test <= T; test++) {

		int N, M;
		cin >> N >> M;
		vector<Edge> graph[401];
		int dist[401];
		

		for (int i = 0; i < M; i++) {
			int s, e, c;
			cin >> s >> e >> c;
			Edge edge = Edge(e, c);
			graph[s].push_back(edge);
		
		}

		int ans = INF;

		for (int i = 1; i <= N; i++) {

			priority_queue<Edge, vector<Edge> , Compare> pq;
			for (int j = 1; j <= N; j++)
				dist[j] = INF;

			pq.push(Edge(i, 0));
			
			while (!pq.empty()) {
				int end = pq.top().end;
				int cost = pq.top().cost;
				pq.pop();

				if (cost > ans)
					continue;

				for (int j = 0; j < graph[end].size(); j++) {
					int next = graph[end][j].end;
					int nextCost = graph[end][j].cost;

					if (dist[next] > cost + nextCost) {
						dist[next] = cost + nextCost;
						pq.push(Edge(next, cost + nextCost));
					}
				}
			}
			ans = min(ans, dist[i]);
		}

		cout << "#" << test << " " << ans << "\n";
		
	}

	return 0;
}

