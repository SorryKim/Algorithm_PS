#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int parent[1001];
int _rank[1001];

struct Edge{
    int u, v, d;

    Edge(int u, int v, int d){
        this->u = u;
        this->v = v;
        this->d = d;
    }

    bool operator<(const Edge& other) const {
        return this->d < other.d;
    }
};

int Find(int n) {
    if (parent[n] == n)
         return parent[n];
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return;

    if (_rank[a] < _rank[b]) 
        swap(a, b);

    parent[b] = a;
    if (_rank[a] == _rank[b]) 
        _rank[a]++;
        
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    vector<bool> MW(N + 1);
    vector<Edge> edges;

    // 학교 성별 입력
    for (int i = 1; i <= N; i++) {
        char ch;
        cin >> ch;
        MW[i] = (ch == 'M'); // true: 남초, false: 여초
    }

    // 도로 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        if (MW[u] != MW[v])
            edges.push_back(Edge{u, v, d});
        
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i <= 1000; i++) 
        parent[i] = i;

    int cnt = 0;
    int sum = 0;

    // 크루스칼 알고리즘
    for (Edge &edge : edges) {
        
        if(Find(edge.u) != Find(edge.v)){ 
            Union(edge.u, edge.v);
            sum += edge.d;
            cnt++;
            // MST 완성
            if (cnt == N - 1) break; 
        }
    }

    // 모든 학교를 연결하지 못한 경우
    if (cnt != N - 1) 
        cout << -1 << '\n';
    else 
        cout << sum << '\n';
    
    return 0;
}
