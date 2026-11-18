#include <string>
#include <vector>
#include <queue>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    vector<vector<int>> graph(n, vector<int>());
    vector<vector<int>> order_graph(n, vector<int>());
    vector<int> degree(n, 0);
    vector<bool> visited(n, false);
    vector<bool> waiting(n, false);
    
    for(auto p : path){
        int a = p[0];
        int b = p[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(auto o : order){
        int a = o[0];
        int b = o[1];
        
        order_graph[a].push_back(b);
        degree[b]++;
    }
    
     if(degree[0] > 0) return false;
    queue<int> q, tmp_q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        // 선행 조건 처리
        for(int next : order_graph[now]){
            degree[next]--;
            
            if(degree[next] == 0 && !visited[next] && waiting[next]){
                visited[next] = true;
                q.push(next);
            }
        }
        
        // 탐색
        for(int next : graph[now]){
            if(visited[next]) continue;
            
            if(degree[next] > 0) {
                waiting[next] = true;
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }
    
    for(auto b : visited) if(!b) return false;
    
    return answer;
}