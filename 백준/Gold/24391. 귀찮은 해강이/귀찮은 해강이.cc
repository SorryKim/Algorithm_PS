#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int> root;
vector<int> _rank;
vector<int> time_table;

int Find(int n){

    if(n == root[n]) return n;
    
    return root[n] = Find(root[n]);
}

void Union(int a, int b){

    int root_a = Find(a);
    int root_b = Find(b);

    if(root_a == root_b) return;

    if(_rank[root_a] > _rank[root_b]) root[root_b] = root_a;
    else if(_rank[root_a] < _rank[root_b]) root[root_a] = root_b;
    else{
        root[root_b] = root_a;
        _rank[root_a]++;
    }

}
void Input(){

    cin >> N >> M;
    root.resize(N + 1);
    _rank.resize(N + 1, 1);
    time_table.resize(N + 1);

    for(int i = 1; i <= N; i++) root[i] = i;

    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        Union(a,b);
    }

    for(int i = 1; i <= N; i++) cin >> time_table[i];
}


int Solve(){

    int ans = -1;
    int now = 0;

    for(int num : time_table){
        
        int next = Find(num);
        if(next != now) ans++;

        now = next;
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    cout << Solve() << "\n";
    return 0;
}