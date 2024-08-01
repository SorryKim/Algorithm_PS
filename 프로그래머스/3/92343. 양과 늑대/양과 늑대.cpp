#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer = 0;

void DFS(int now, int sheep, int wolf, queue<int> q, vector<vector<int>> (&tree), vector<int> &info) {
    
    if(info[now] == 0)
        sheep++;
    else
        wolf++;
    
    if(wolf >= sheep)
        return;
    
    answer = max(answer, sheep);
    
    for(auto next : tree[now])
        q.push(next);
    
    int N = q.size();
    while(N--){
        int next = q.front();
        q.pop();
        DFS(next, sheep, wolf, q, tree, info);
        q.push(next);
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> tree(info.size(), vector<int>());
    
    for(auto edge : edges){
        int start = edge[0];
        int end = edge[1];
        
        tree[start].push_back(end);
    }
    queue<int> q;
    DFS(0, 0, 0, q, tree, info);
    
    return answer;
}