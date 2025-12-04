#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;

int N, M, T;
set<int> scity;
vector<pair<int, int>> city, query;

void input(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T;
    city.resize(N + 1);
    for(int i = 1; i <= N; i++){
        int s, x, y;
        cin >> s >> x >> y;
        
        if(s == 1) scity.insert(i);

        city[i] = {x, y};
    }

    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        query.push_back({a, b});
    }

    return;
}

int calc(const pair<int, int> &p1, const pair<int, int> &p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int getScity(int idx){
    int result = INF;
    for(int s : scity) result = min(result, calc(city[idx], city[s]));
    return result;
}

void solve(){
    
    
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

    for(auto q : query){

        int a = q.first;
        int b = q.second;

        // 1. 그냥 걸어가기
        int dist = calc(city[a], city[b]);

        // 2. 텔포 이용가능한지
        int walkA = scity.count(a) ? 0 : getScity(a);
        int walkB = scity.count(b) ? 0 : getScity(b);

        int walkT = walkA + walkB + T;

        cout << min(dist, walkT) << "\n";
    }

    return;
}

int main(){

    input();
    solve();
    return 0;
}