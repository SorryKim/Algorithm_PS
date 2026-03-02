#include <iostream>
#include <vector>

using namespace std;

int Find(int n, vector<int> &parent){
    
    if(n == parent[n]) return parent[n];

    return parent[n] = Find(parent[n], parent);
}

void Union(int a, int b, vector<int> &parent, vector<int> &_rank){

    int pa = Find(a, parent);
    int pb = Find(b, parent);

    if(_rank[pa] > _rank[pb]) parent[pb] = pa;
    else if(_rank[pb] > _rank[pa]) parent[pa] = pb;
    else{
        parent[pb] = pa;
        _rank[pa]++;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    int TC;
    cin >> TC;

    for(int tc = 1; tc <= TC; tc++){
        int n, m, k;
        cin >> n >> k;

        vector<int> parent(n, 0);
        vector<int> _rank(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;

        for(int i = 0; i < k; i++){
            int a, b;
            cin >> a >> b;
            Union(a, b, parent, _rank);
        }

        cin >> m;
        vector<pair<int, int>> v;
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        cout << "Scenario " << tc << ":\n";
        for(auto a : v){
            int pa = Find(a.first, parent);
            int pb = Find(a.second, parent);

            if(pa == pb) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        cout << "\n";
    }


    return 0;
}