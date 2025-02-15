#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<pair<int,int>>> edges;
vector<int> dist; // 루트랑 해당노드의 거리
vector<int> depth;
vector<int> parent;

// 공통 조상 찾기
int LCA(int a, int b){

    int depthA = depth[a];
    int depthB = depth[b];

    while(depthA > depthB){
        depthA--;
        a = parent[a];
    }

    while(depthB > depthA){
        depthB--;
        b = parent[b];
    }

    while(a != b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int GetDist(int a, int b){
    
    int target = LCA(a, b);
    return dist[a] + dist[b] - 2 * dist[target]; // 두 노드 사이의 거리
}

void MakeTree(int node, int par){
    
    parent[node] = par;

    for(auto temp : edges[node]){
        int child = temp.first;
        if(child == par) continue;
        
        depth[child] = depth[node] + 1;
        dist[child] = dist[node] + temp.second;
        MakeTree(child, node);
    }

    return;
}

void Input(){

    cin >> N;

    edges.resize(N + 1);
    depth.resize(N + 1, 0);
    dist.resize(N + 1, 0);
    parent.resize(N + 1, 0);

    for(int i = 1; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    MakeTree(1, -1);
    
    // 두 노드 사이 거리 출력
    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        cout << GetDist(a,b) << '\n';
    }

    return 0;
}