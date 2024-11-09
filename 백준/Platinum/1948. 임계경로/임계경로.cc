#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<vector<pair<int,int>>> roads;
int start, destination;
bool visited[10001][10001];
int cnt = 0;
void Input(){
    cin >> N >> M;
    roads = vector<vector<pair<int, int>>>(N + 1);

    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        roads[u].push_back({v,w});
    }

    cin >> start >> destination;
}

void CountPath(int now, vector<vector<int>> &prev){

    
    for(int node : prev[now]){
        if(!visited[node][now]){
            cnt++;
            visited[node][now] = true;
            CountPath(node, prev);
        }
    }
}

pair<int,int> Solve(){

    vector<int> dist(N + 1, 0);
    vector<vector<int>> prev(N + 1);
    dist[start] = 0;

    priority_queue<pair<int,int>> pq;
    
    pq.push({0, start});

    // 최장거리를 구함
    while(!pq.empty()){

        int now_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(now_dist < dist[now])
            continue;
        
        for(auto road : roads[now]){

            int next = road.first;
            int next_dist = now_dist + road.second;
            if(next_dist > dist[next]){
                dist[next] = next_dist;
                prev[next].clear();
                prev[next].push_back(now);
                pq.push({next_dist, next});
            }else if(next_dist == dist[next])
                prev[next].push_back(now);
        }
    }
    
    
    // 목적지의 길이를 구함
    CountPath(destination, prev);
    return {dist[destination], cnt};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    pair<int, int> answer = Solve();
    cout << answer.first << '\n';
    cout << answer.second << '\n';

    return 0;
}
