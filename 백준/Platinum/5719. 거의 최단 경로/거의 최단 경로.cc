#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N, M, S, D;
const int INF = 1e9;

// 다익스트라
vector<int> Dijkstra(vector<vector<pair<int,int>>> &graph, vector<vector<int>> &parents) {
    
    vector<int> dist(N, INF);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        int now_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (now_dist > dist[now]) continue;

        for (auto &edge : graph[now]) {
            int next = edge.first;
            int weight = edge.second;
            int next_dist = now_dist + weight;

            if (dist[next] > next_dist) {
                dist[next] = next_dist;
                parents[next].clear();
                parents[next].push_back(now);
                pq.push({next_dist, next});
            } else if (dist[next] == next_dist) {
                parents[next].push_back(now);
            }
        }
    }

    return dist;
}

// 최소 거리 삭제
void Remove_path(vector<vector<int>> &parents, vector<vector<pair<int,int>>> &graph) {
    
    queue<int> q;
    q.push(D);
    vector<bool> visited(N, false);
    visited[D] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int prev : parents[now]) {
            // prev에서 now로 가는 간선을 제거
            for (int i = 0; i < graph[prev].size(); i++) {
                if (graph[prev][i].first == now) {
                    graph[prev].erase(graph[prev].begin() + i);
                    break;
                }
            }

            if (!visited[prev]) {
                visited[prev] = true;
                q.push(prev);
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    while (true){
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;
        cin >> S >> D;
        
        vector<vector<pair<int, int>>> graph(N);
        vector<vector<int>> parents(N); // 부모 저장
        for(int i = 0 ; i < M; i++){
            int u,v,w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }

        // 다익스트라 1회 진행
        Dijkstra(graph, parents);

        // 최소거리 path 삭제
        Remove_path(parents, graph);
        
        // 최소거리 삭제후 다시 다익스트라 진행
        vector<int> dist = Dijkstra(graph, parents);

        // 정답 출력
        int answer = dist[D] == INF ? -1 : dist[D];
        cout << answer << '\n';
    }

    return 0;
}
