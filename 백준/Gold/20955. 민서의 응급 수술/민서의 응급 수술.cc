#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

vector<int> parent;
vector<int> _rank;
int ans = 0;

int Find(int a){

    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){

    int parent_a = Find(a);
    int parent_b = Find(b);

    if(parent_a == parent_b) return;

    // 랭크 낮은 쪽을 높은 쪽에 붙임
    if(_rank[parent_a] < _rank[parent_b]) parent[parent_a] = parent_b;
    else if(_rank[parent_a] > _rank[parent_b]) parent[parent_b] = parent_a;
    else{
        // 둘이 높이가 같음 랭크 증가
        parent[parent_b] = parent_a;
        _rank[parent_a]++;
    }

}

void Input(){

    cin >> N >> M;
    parent.resize(N + 1, 0);
    _rank.resize(N + 1, 1);

    for(int i = 1; i <= N; i++) parent[i] = i;
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        
        int parent_a = Find(a);
        int parent_b = Find(b);

        // 싸이클이 생기는 경우, 연결 끊기
        if(parent_a == parent_b) ans++;
        else Union(a, b);
    }

}

void Solve(){

    
    set<int> temp;
    for(int i = 1; i <= N; i++){
        temp.insert(Find(i));
    }

    ans += (temp.size() - 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();
    cout << ans << "\n";
    return 0;
}