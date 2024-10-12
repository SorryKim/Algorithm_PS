#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int n, int start, int destination, vector<vector<int>> &graph){
    
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    queue<pair<int,int>> q;
    q.push({start, 0});
    
    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(now == destination)
            return time;
        
        for(auto next : graph[now]){
            if(visited[next])
                continue;
            visited[next] = true;
            q.push({next, time + 1});
        }
    }
    
    return -1;
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> graph(n + 1);
    
    for(auto road : roads){
        int a = road[0];
        int b = road[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(auto source : sources){
        int result =  BFS(n, source, destination, graph);
        answer.push_back(result);
    }
    
    return answer;
}