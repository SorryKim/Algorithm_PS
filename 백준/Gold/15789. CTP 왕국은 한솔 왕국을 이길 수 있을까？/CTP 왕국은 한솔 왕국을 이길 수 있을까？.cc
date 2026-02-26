#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int N, M;
int C, H, K;
vector<int> parent, power;

int Find(int n){
    if(n == parent[n]) return n;
    return parent[n] = Find(parent[n]);
}


void Union(int a, int b){
    int pa = Find(a);
    int pb = Find(b);

    if(pa == pb) return;

    if(power[pa] < power[pb]){
        parent[pa] = pb;
        power[pb] += power[pa];
    }
    else{
        parent[pb] = pa;
        power[pa] += power[pb];
    }
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    parent.resize(N + 1);
    power.resize(N + 1, 1);

    for(int i = 1; i <= N; i++) parent[i] = i;

    for(int i = 0; i < M; i++){
        int X, Y;
        cin >> X >> Y;
        Union(X, Y);
    }

    cin >> C >> H >> K;
}

int solve(){

    int pH = Find(H);

    vector<pair<int,int>> candidate;
    unordered_set<int> roots;

    for(int i = 1; i <= N; i++){
        int r = Find(i);
        if(r != pH)
            roots.insert(r);
    }

    for(auto r : roots) candidate.push_back({r, power[r]});
    

    // 집합 크기 내림차순 정렬
    sort(candidate.begin(), candidate.end(),
         [](const pair<int,int>& a, const pair<int,int>& b){
             return a.second > b.second;
         });

    // K개 집합을 C와 합치기
    int limit = min(K, (int)candidate.size());
    for(int i = 0; i < limit; i++) Union(candidate[i].first, C);
    
    return power[Find(C)];
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}