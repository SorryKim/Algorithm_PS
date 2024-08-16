#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int Find(int n, vector<int> &parent){

    if(n == parent[n])
        return parent[n];
    else
        return Find(parent[n], parent);
}

void Union(int a, int b, vector<int> &parent, vector<int> &rank){

    int rootA = Find(a, parent);
    int rootB = Find(b, parent);

    if(rootA == rootB)
        return;

    if(rank[rootA] > rank[rootB]){
        parent[rootB] = rootA;
    }else if(rank[rootA] < rank[rootB]){
        parent[rootA] = rootB;
    }else{
        parent[rootB] = rootA;
        rank[rootA] += 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1, 0);
    vector<int> rank(n + 1, 0);

    for(int i = 0; i <= n; i++){
        parent[i] = i;
        rank[i] = 1;
    }


    for(int cnt = 1; cnt <= m; cnt++){

        int a, b;
        cin >> a >> b;

        if(Find(a, parent) == Find(b, parent)){
            cout << cnt;
            return 0;
        }

        Union(a,b,parent, rank);

    }

    cout << 0;
    return 0;
}
