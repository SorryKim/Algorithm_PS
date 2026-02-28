#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;
int V, E, P;
vector<vector<pair<int, int>>> graph;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E >> P;
    graph.resize(V + 1, vector<pair<int, int>>());

    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    return;
}

vector<int> dijkstra(int start){
    
    vector<int> cost(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    cost[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int c = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(cost[now] < c) continue;

        for(auto a : graph[now]){

            int next = a.first;
            int nc = c + a.second;
            if(cost[next] > nc){
                cost[next] = nc;
                pq.push({nc, next});
            }
        }
    }

    return cost;
}

bool solve(){

    vector<int> cost1 = dijkstra(1);
    vector<int> cost2 = dijkstra(P);
    
    // 1. 출발 - 건우 - 마산
    int dist1 = cost1[P] + cost2[V];
    
    // 2. 출발 - 마산
    int dist2 = cost1[V];

    return dist1 == dist2;
}

int main(){
    input();
    
    if(solve()) cout << "SAVE HIM\n";
    else cout << "GOOD BYE\n";
    return 0;
}