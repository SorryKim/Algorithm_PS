#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void DFS(const string& now, unordered_map<string, vector<string>>& adj, vector<string>& route) {
    
    while (!adj[now].empty()) {
        string next = adj[now].back();
        adj[now].pop_back();
        DFS(next, adj, route);
    }
    
    route.push_back(now);
}

vector<string> solution(vector<vector<string>> tickets) {
    
    vector<string> route;
    unordered_map<string, vector<string>> adj;
    
    // 인접 리스트 생성
    for (const auto& ticket : tickets) {
        adj[ticket[0]].push_back(ticket[1]);
    }
    
    // 각 노드의 인접 리스트를 사전순으로 정렬
    for (auto& [key, value] : adj) {
        sort(value.begin(), value.end(), greater<string>());
    }
    
    
    DFS("ICN", adj, route);
    
    reverse(route.begin(), route.end());
    return route;
}