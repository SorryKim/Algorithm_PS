#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<pair<int,int>>> graph;

void Input(){

    cin >> N >> M;
    graph.resize(N + 1);
    
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
}

int Solve(){

    vector<int> dist(N + 1, INF);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});


    // 다익스트라
    while(!pq.empty()){
        
        int now_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < now_dist) continue;

        for(auto temp : graph[now]){
            int next = temp.first;
            int next_dist = temp.second + now_dist;
            if(dist[next] > next_dist){
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    return dist[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    cout << Solve() << '\n';

    return 0;
}
