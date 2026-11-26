#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{

    int a, b, c;

    bool operator< (const Edge &other) const {
        return this->c < other.c;
    }
};

vector<int> parent, _rank;

int find(int n) {
    if (n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) return;

    if (_rank[pa] > _rank[pb]) parent[pb] = pa;
    else if (_rank[pa] < _rank[pb]) parent[pa] = pb;
    else {
        parent[pb] = pa;
        _rank[pa]++;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    parent.resize(N, 0);
    _rank.resize(N, 0);

    vector<Edge> edges;
    int sum1 = 0;

    // 가지고 있는 전선 계산
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        for(int j = 0; j < N; j++){
            char ch = s[j];
            if(ch == '0'){

            }else if(ch >= 'a' && ch <= 'z'){
                int cost = ch - 'a' + 1;
                edges.push_back({i, j, cost});
                sum1 += cost;
            }else if(ch >= 'A' && ch <= 'Z'){
                int cost = ch - 'A' + 27;
                edges.push_back({i, j, cost});
                sum1 += cost;
            }
        }
    }   

    // kruskal algorithm 사용
    for(int i = 0; i < N; i++) parent[i] = i;
    sort(edges.begin(), edges.end());
    int sum2 = 0;

    for(auto edge : edges){
        int a = edge.a;
        int b = edge.b;
        int c = edge.c;

        if(find(a) == find(b)) continue;
        Union(a, b);
        sum2 += c;
    }

    bool b = true;
    for(int i = 0; i < N; i++){
        if(find(0) != find(i)){
            b = false;
            break;
        }
    }

    int answer = b ? sum1 - sum2 : -1;
    cout << answer << "\n";

    return 0;
}