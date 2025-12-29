#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
vector<int> parent, _rank;

int Find(int n){

    if(parent[n] == n) return n;
    else return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    int pa = Find(a);
    int pb = Find(b);

    if(pa == pb) return;

    if(_rank[pa] > _rank[pb]){
        parent[pb] = pa;
    }else if(_rank[pb] > _rank[pa]){
        parent[pa] = pb;
    }else{
        parent[pb] = pa;
        _rank[pa]++;
    }
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    parent.resize(N + 1);
    _rank.resize(N + 1, 1);

    for(int i = 1; i <= N; i++) parent[i] = i;

    for(int i = 0; i < N - 2; i++){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    return;
}

void solve(){

    set<int> s;
    for(int i = 1; i <= N; i++) s.insert(Find(i));

    
    if(N == 2) {
        cout << "1 2" << '\n';
        return;
    }

    auto ans = s.begin();
    cout << *ans << " ";
    ans++;
    cout << *ans << "\n";

    return;
}

int main(){

    input();
    solve();
    return 0;
}