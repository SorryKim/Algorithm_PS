#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000000 + 7;
int N, M;
vector<vector<int>> graph;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.resize(N + 1, vector<int>());
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    return;
}

int solve(){
    
    vector<int> dp(N + 1, 1);
    
    for(int step = 1; step <= 7; step++){
        vector<int> temp(N + 1, 0);
        
        for(int i = 1; i <= N; i++){
            for(int j : graph[i]){
                temp[j] = (temp[j] + dp[i]) % MOD;
            }
        }

        dp = temp;
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) ans = (ans + dp[i]) % MOD;

    return ans;
}

int main(){
    
    input();
    cout << solve() << "\n";

    return 0;
}