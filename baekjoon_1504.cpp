// 특정한 최단 경로 / baekjoon_1504.cpp
// https://www.acmicpc.net/problem/1504

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int N, E;
int v1, v2;
vector<pair<int, int>> graph[801];
int dist[801], result[801];

void Input() {

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
    cin >> v1 >> v2;
}

int Dijkstra(int start, int end) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });
    for (int i = 1; i <= 800; i++)
        dist[i] = INF;
    dist[start] = 0;

    while (!pq.empty()) {

        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int nextCost = graph[now][i].second;

            if (dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                pq.push({ dist[next], next});
            }
        }
    }
    
    return dist[end];
}

void Solve() {
    
    int result1, result2;
    
    // 1 -> v1 -> v2 -> N
    int r1 = Dijkstra(1, v1);
    int r2 = Dijkstra(v1, v2);
    int r3 = Dijkstra(v2, N);
  
    if (r1 == INF || r2 == INF || r3 == INF)
        result1 = INF;
    else
        result1 = r1 + r2 + r3;
    
    // 1 -> v2 -> v1 -> N
    r1 = Dijkstra(1, v2);
    r2 = Dijkstra(v2, v1);
    r3 = Dijkstra(v1, N);

    if (r1 == INF || r2 == INF || r3 == INF)
        result2 = INF;
    else
        result2 = r1 + r2 + r3;

    int result = min(result1, result2);
    cout << ((result == INF) ? -1 : result);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();

}
