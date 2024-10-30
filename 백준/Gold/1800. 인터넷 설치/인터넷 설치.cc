#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, P, K;
vector<vector<pair<int,int>>> graph;

bool Dijkstra(int mid) {

    vector<int> dist(N + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){

        int cnt = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < cnt)
            continue;
        
        for(auto node : graph[now]){

            int next = node.first;
            int value = node.second;
            int next_cnt = cnt;

            if(value > mid)
                next_cnt++;
            
            if(next_cnt > K)
                continue;
            
            if(dist[next] > next_cnt){
                dist[next] = next_cnt;
                pq.push({next_cnt, next});
            }
        }
    }

    return dist[N] != INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = -1;
    int start = 0;
    int end = 0;

    cin >> N >> P >> K;
    graph = vector<vector<pair<int,int>>>(N + 1);
    for(int i = 0; i < P; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});

        end = max(end, c);
    }

    while(start <= end){
        int mid = (start + end) / 2;

        if(Dijkstra(mid)){
            answer = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }

    cout << answer << '\n';

    return 0;
}
