#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;

int N, M;
vector<int> tree[MAX];
int parent[MAX];
int depth[MAX];


void DFS(int node, int par){

    parent[node] = par;
    depth[node] = depth[par] + 1;

    for(int next : tree[node]){
        if(par != next) DFS(next, node);
    }

}

int LCA(int u, int v) {
   
    while (depth[u] > depth[v]) u = parent[u];
    while (depth[v] > depth[u]) v = parent[v];

    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1, 0); 

    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }

    return 0;
}
