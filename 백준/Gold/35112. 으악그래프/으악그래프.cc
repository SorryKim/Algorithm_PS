#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    graph.resize(N + 1, vector<int>());
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    return;
}

bool solve(){
    
    if(N - 1 > M - 2) return true;
    return false;
}

int main(){
    input();
    if(solve()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}