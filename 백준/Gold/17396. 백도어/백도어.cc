#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;
int N, M;
vector<int> sight;
vector<vector<pair<int,int>>> graph;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    sight.resize(N);
    graph.resize(N);

    for(int i = 0; i < N; i++) cin >> sight[i];
    for(int i = 0; i < M; i++){
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
}

long long solve(){
    vector<long long> dist(N, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [cost, now] = pq.top();
        pq.pop();

        if(dist[now] < cost) continue;

        for(auto [next, w] : graph[now]){
            if(next != N - 1 && sight[next] == 1) continue; // 시야 있는 곳은 스킵

            long long next_cost = cost + w;
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }

    return dist[N - 1] == INF ? -1 : dist[N - 1];
}

int main(){
    input();
    cout << solve() << "\n";
}
