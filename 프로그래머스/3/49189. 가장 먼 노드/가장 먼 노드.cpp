#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int djikstra(int N, vector<vector<int>> &edge){
    vector<int> dist(N + 1, INT_MAX);
    vector<vector<int>> graph(N + 1, vector<int>());
    for(auto e : edge){
        int a = e[0];
        int b = e[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>,  greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int next : graph[now]){
            if(dist[next] > cost + 1){
                dist[next] = 1 + cost;
                pq.push({dist[next], next});
            }
        }
    }
    
    // 리프 계산
    sort(dist.begin() + 1, dist.end());
    
    int v = dist[N];
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        if(v == dist[i]) result++;
    }
    
    //for(int i = 1; i <= N; i++) cout << dist[i] << " ";
    return result;
}


int solution(int n, vector<vector<int>> edge) {
    int answer = djikstra(n, edge);
    return answer;
}