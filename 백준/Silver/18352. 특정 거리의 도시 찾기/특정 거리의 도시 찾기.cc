#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    const int INF = 1e9;
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    graph.resize(N + 1);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    // 다익스트라로 시작지점에서의 최단거리 구하기
    vector<int> dist(N + 1, INF);
    dist[X] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,X});
    while(!pq.empty()){

        int now_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < now_dist) continue;

        for(int next : graph[now]){
            int poo = dist[now] + 1; // 노드간 거리는 1
            if(dist[next] > poo){
                dist[next] = poo;
                pq.push({poo, next});
            }
        }
    }

    // 정답 출력
    vector<int> answer;
    for(int i = 1; i <= N; i++){
        if(dist[i] == K) answer.push_back(i);
    }

    if(answer.empty()) cout << -1 << '\n';
    else for(int ans : answer) cout << ans << '\n';

    return 0;
}