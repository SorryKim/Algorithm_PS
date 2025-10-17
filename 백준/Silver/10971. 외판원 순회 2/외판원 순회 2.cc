#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int W[10][10];
int dp[10][1 << 10]; // dp[now][visited]
const int INF = 1e9;

void input(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    // dist 입력 받기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> W[i][j];
        }
    }

    // dp 테이블 초기화
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 1 << 10; j++){
            dp[i][j] = -1;
        }
    }

}

int dfs(int now, int visited){

    // 종료 조건
    if(visited == (1 << N) - 1){
        if(W[now][0] == 0) return INF;
        return W[now][0];
    }

    if(dp[now][visited] != -1) return dp[now][visited];
    dp[now][visited] = INF;

    for(int i = 0; i < N; i++){
        if(visited & (1 << i)) continue;
        if(W[now][i] == 0) continue;

        dp[now][visited] = min(dp[now][visited], W[now][i] + dfs(i, visited | (1 << i)));
    }

    return dp[now][visited];
}

int main(){

    input();
    cout << dfs(0, 1 << 0) << "\n";

}