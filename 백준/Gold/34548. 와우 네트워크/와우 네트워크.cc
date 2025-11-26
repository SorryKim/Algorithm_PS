#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
struct Connect{
    int u, v, t;

    bool operator<(const Connect &other) const{
        return t < other.t;
    }
};

int N, M, T;
int parent[MAX + 1];
int _rank[MAX + 1];
vector<Connect> connects;


int Find(int a){
    if(a == parent[a]) return parent[a];
    return parent[a] = Find(parent[a]);
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
    
    return;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> T;
    for(int i = 1; i <= M; i++){
        int u, v, s;
        cin >> u >> v >> s;
        connects.push_back({u, v, s});
    }

    for(int i = 1; i <= N; i++) parent[i] = i;
}

long long solve() {

    sort(connects.begin(), connects.end());

    long long ans = 0;
    int cnt = N;
    int prev = 1;

    for (auto &now : connects) {

        if (now.t > prev) {
            ans += (long long)(now.t - prev) * cnt; 
            prev = now.t;
        }

        if (Find(now.u) != Find(now.v)) {
            Union(now.u, now.v);
            cnt--;
        }
    }

    ans += (long long)(T - prev + 1) * cnt;
    return ans;
}


int main(){
    input();
    cout << solve() << "\n";
    
    return 0;
}