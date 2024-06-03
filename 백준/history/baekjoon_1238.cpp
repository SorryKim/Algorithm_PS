// 파티 / baekjoon_1238.cpp
// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int N, M, X;
vector<pair<int, int>> graph[1001];
int dist[1001], result[1001];


void Input() {

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int start, end, dist;
        cin >> start >> end >> dist;
        graph[start].push_back({ end,dist });
    }
}

void Dijkstra(int start) {

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, start });
    for (int i = 0; i <= 1000; i++)
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
                pq.push({ dist[next], next });
            }
        }
    }

}

void Solve() {

    // 각 마을에서 X마을 까지의 최단거리 갱신
    for (int i = 1; i <= N; i++) {
        Dijkstra(i);
        result[i] = dist[X];
    }
    
    // X마을에서 각마을까지 최단거리 갱신
    Dijkstra(X);
    
    // 결과 갱신
    for (int i = 1; i <= N; i++)
        result[i] += dist[i];

    // 결과 출력
    int answer = 0;
    for (int i = 1; i <= N; i++)
        answer = max(answer, result[i]);
    cout << answer << "\n";
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();

}
