#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> graph;
vector<bool> check;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    check.resize(100, true);

    for(int i = 1; i <= N; i++){
        int a, b;
        cin >> a >> b;
        graph[i] = {a, b};
    }

    return;
}

int solve(){
    
    // dp[a][b]: a번 이동해서 b번 사람이 도달 가능한 지
    vector<vector<int>> dp(100, vector<int>(N + 1, 0));

    dp[0][1] = true;
    
    dp[1][graph[1].first] = true;
    dp[1][graph[1].second] = true;


    for(int i = 2; i <= 99; i++){
        for(int j = 1; j <= N; j++){
            if(dp[i - 1][j]) {
                dp[i][graph[j].first] = true;
                dp[i][graph[j].second] = true;
            }
        }
    }

    for(int i = 10; i <= 99; i++){
        if(!dp[i][1]) return i;
    }
    
    return -1;
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}