#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, k;
vector<pair<int,int>> fee;
int parent[10001];
int _rank[10001];

int Find(int num){
    
    if(parent[num] == num)
        return parent[num];
    
    return parent[num] = Find(parent[num]);
}

void Union(int a, int b){

    a = Find(a);
    b = Find(b);

    if(a == b)
        return;
    
    if(_rank[a] < _rank[b])
        swap(a,b);

    parent[b] = a;
    if(_rank[a] == _rank[b])
        _rank[a]++;

    return;
}

void Input(){

    cin >> N >> M >> k;
    for(int i = 1; i <= N; i++){
        int money;
        cin >> money;
        fee.push_back({money, i});
        parent[i] = i;
        _rank[i] = 1;
    }

    for(int i = 0; i < M; i++){
        int v, w;
        cin >> v >> w;
        Union(v,w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();

    // 가격 오름차순 정렬
    sort(fee.begin(), fee.end());

    int answer = fee[0].first;
    int now = fee[0].second;

    for(int i = 1; i < fee.size(); i++){

        int cost = fee[i].first;
        int next = fee[i].second;

        if(Find(next) != Find(now)){
            Union(now, next);
            answer += cost;
        }
    }

    bool flag = true;
    int temp = Find(1);
    for(int i = 2; i <= N; i++){
        if(temp != Find(i)){
            flag = false;
            break;
        }
    }

    if(flag && k >= answer) cout << answer << "\n";
    else cout << "Oh no\n";
     
    return 0;
}
