#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const long long INF = 1e15;
int N, M;
int oil_price[2501];
vector<pair<int, int>> graph[2501];
long long cost[2501][2501]; // [도시][해당경로의 최소 기름가격]

struct Path {
    int now, oil;
    long long now_cost;
    Path(int a, long long b, int c) : now(a), now_cost(b), oil(c) {}

    bool operator<(const Path &other) const {
        return now_cost > other.now_cost; 
    }
};

void Dijkstra() {

    priority_queue<Path> pq;
    pq.push(Path(1, 0, oil_price[1]));
    cost[1][oil_price[1]] = 0;

    while (!pq.empty()) {
        Path path = pq.top();
        pq.pop();

        int now = path.now;
        long long now_cost = path.now_cost;
        int oil = path.oil;

        if (cost[now][oil] < now_cost)
            continue;

        for (auto edge : graph[now]) {
            int next = edge.first;
            long long next_dist = edge.second;

            int next_oil = min(oil, oil_price[next]);
            long long next_cost = now_cost + next_dist * oil;

            if (cost[next][next_oil] > next_cost) {
                cost[next][next_oil] = next_cost;
                pq.push(Path(next, next_cost, next_oil));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> oil_price[i];
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= 2500; j++) 
            cost[i][j] = INF;
        
    Dijkstra();

    long long answer = INF;
    for (int i = 1; i <= 2500; i++)
        answer = min(answer, cost[N][i]);
    

    cout << answer << '\n';

    return 0;
}
