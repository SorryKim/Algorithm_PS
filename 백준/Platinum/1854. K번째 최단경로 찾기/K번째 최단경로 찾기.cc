#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // 다익스트라로 K개까지 경로를 구하기
    const long long INF = 1e15;
    vector<vector<long long>> dist(N + 1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int now = pq.top().second;
        long long now_dist = pq.top().first;
        pq.pop();

        if (dist[now].size() >= K)
            continue;

        // 현재 노드까지의 거리를 dist[now]에 추가
        dist[now].push_back(now_dist);

        for (auto a : graph[now])
        {
            int next = a.first;
            long long next_dist = now_dist + a.second;
            pq.push({next_dist, next});
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (dist[i].size() >= K)
            cout << dist[i][K - 1] << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
