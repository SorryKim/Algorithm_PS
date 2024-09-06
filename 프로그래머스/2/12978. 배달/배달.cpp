#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    const int INF = 987654321;
    vector<vector<pair<int,int>>> graph(N + 1, vector<pair<int,int>>());
    vector<int> dist(N + 1, INF);
    
    for(auto now : road){
        int start = now[0];
        int end = now[1];
        int cost = now[2];
        
        graph[start].push_back({end,cost});
        graph[end].push_back({start,cost});
    }
    
    dist[1] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        
        int now_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(auto next : graph[now]){
            int next_pos = next.first;
            int next_dist = next.second;
            if(dist[next_pos] > now_dist + next_dist){
                dist[next_pos] = now_dist + next_dist;
                pq.push({now_dist + next_dist, next_pos});
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(dist[i] <= K)
            answer++;
    }

    return answer;
}