#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int dist[16][16];
int dp[16][1 << 16]; // dp[now][visited]
const int INF = 1e9;


void input(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 1 << 16; j++){
            dp[i][j] = -1;
        }
    }

    // dist 입력 받기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dist[i][j];
        }
    }

}

int dfs(int now, int visited){

    int allVisited = (1 << N) - 1;
    if(visited == allVisited){
        if(dist[now][0] == 0) return INF;
        return dist[now][0];
    }

    if(dp[now][visited] != -1) return dp[now][visited];
    dp[now][visited] = INF; // 초기값 설정

    for(int next = 0; next < N; next++){
        if(visited & (1 << next)) continue;
        if(dist[now][next] == 0) continue;

        dp[now][visited] = min(dp[now][visited], dist[now][next] + dfs(next, visited | (1 << next)));
    }

    return dp[now][visited];
}

int main(){

    input();
    cout << dfs(0, 1 << 0) << "\n";

}