#include <iostream>
#include <vector>

using namespace std;

int N;
long long cntD, cntG;
vector<int> degree;
vector<pair<int,int>> edges;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cntD = 0;
    cntG = 0;
    degree.resize(N + 1, 0);

    for(int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        edges.push_back({u, v});
    }
}

string solve() {

    // 'ㅈ' 계산
    for(int i = 1; i <= N; i++){
        long long d = degree[i];
        if(d >= 3){
            cntG += (d * (d - 1) * (d - 2)) / 6; // C(d, 3)
        }
    }

    // 'ㄷ' 계산
    for(auto &e : edges){
        long long u = e.first;
        long long v = e.second;
        
        if(degree[u] >= 2 && degree[v] >= 2){
            cntD += (long long)(degree[u] - 1) * (degree[v] - 1);
        }
    }

    // 결과 판정
    if(cntD > cntG * 3) return "D";
    else if(cntD < cntG * 3) return "G";
    else return "DUDUDUNGA";
}

int main() {
    input();
    cout << solve() << "\n";
    return 0;
}
