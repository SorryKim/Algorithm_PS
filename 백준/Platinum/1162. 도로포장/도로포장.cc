#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int now;
    long long cost;
    int pack; // 포장한 도로 수

    Edge(int now, long long cost, int pack) {
        this->now = now;
        this->cost = cost;
        this->pack = pack;
    }

    bool operator< (const Edge& other) const {
        return cost > other.cost;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    const long long INF = 1e15; // INF 값을 충분히 크게 설정
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, long long>>> graph(N + 1); 

    for (int i = 0; i < M; i++) {
        int u, v;
        long long w; 
        cin >> u >> v >> w;

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    // 다익스트라
    vector<vector<long long>> dist(N + 1, vector<long long>(K + 1, INF));
    priority_queue<Edge> pq;

    dist[1][0] = 0;
    pq.push(Edge(1, 0, 0));

    while (!pq.empty()) {
        int now = pq.top().now;
        long long now_cost = pq.top().cost;
        int pack = pq.top().pack;
        pq.pop();

        
        if (dist[now][pack] < now_cost)
            continue;

        for (auto& a : graph[now]) {
            int next = a.first;
            long long cost = a.second;

            // 포장하지 않는 경우
            long long next_cost = now_cost + cost;
            if (dist[next][pack] > next_cost) {
                dist[next][pack] = next_cost;
                pq.push(Edge(next, next_cost, pack));
            }

            // 포장하는 경우
            if (pack < K) {
                if (dist[next][pack + 1] > now_cost) {
                    dist[next][pack + 1] = now_cost;
                    pq.push(Edge(next, now_cost, pack + 1));
                }
            }
        }
    }

    // 정답 출력
    long long answer = INF;
    for (long long now : dist[N])
        answer = min(answer, now);

    cout << answer << '\n';

    return 0;
}
