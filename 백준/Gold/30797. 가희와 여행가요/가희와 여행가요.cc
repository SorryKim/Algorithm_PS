#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int from, to, cost, time;

    bool operator<(const Edge& other) const {
        if(cost == other.cost) return time < other.time;
        return cost < other.cost;
    }
};

int N, Q;
vector<Edge> edges;
vector<int> parent;
vector<int> _rank;
long long min_time = 0;
long long min_cost = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;

    for(int i = 0; i < Q; i++){
        int from, to, cost, time;
        cin >> from >> to >> cost >> time;
        edges.push_back({from, to, cost, time});
    }

    parent.resize(N + 1, 0);
    _rank.resize(N + 1, 1);
    for(int i = 1; i <= N; i++) parent[i] = i;

    return;
}

int Find(int n){
    if(parent[n] == n) return parent[n];

    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){

    int pa = Find(a);
    int pb = Find(b);
    if(pa == pb) return;

    if(_rank[pa] > _rank[pb]) parent[pb] = pa;
    else if(_rank[pb] > _rank[pa]) parent[pa] = pb;
    else{
        parent[pb] = pa;
        _rank[pa]++;
    }
    
}

bool solve(){
    sort(edges.begin(), edges.end());

    for(Edge edge : edges){
        int pa = Find(edge.from);
        int pb = Find(edge.to);
        if(pa == pb) continue;
        Union(edge.from, edge.to);
        min_time = max(min_time, (long long)edge.time);
        min_cost += edge.cost;
    }

    int p = Find(1);
    for(int i = 2; i <= N; i++){
        if(p != Find(i)) return false;
    }

    return true;
}

int main() {
    
    input();
    if(solve()) cout << min_time << " " << min_cost << "\n";
    else cout << -1 << "\n";

    return 0;
}