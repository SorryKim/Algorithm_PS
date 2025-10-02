#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, K;

map<pair<pair<int,int>, pair<int,int>>, bool> blocked;

void input(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    cin >> K;

    for(int i = 0; i < K; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        blocked[{{a,b}, {c,d}}] = true;
        blocked[{{c,d}, {a,b}}] = true;
    }
}

long long solve(){
    long long dp[101][101] = {0};
    dp[0][0] = 1;
    
    for(int x = 0; x <= N; x++){
        for(int y = 0; y <= M; y++){

            // x방향 체크
            if(x > 0 && !blocked[{{x - 1, y}, {x, y}}]) dp[x][y] += dp[x - 1][y];
            // y방향 체크 
            if(y > 0 && !blocked[{{x, y - 1}, {x, y}}]) dp[x][y] += dp[x][y - 1];
        }
    }

    return dp[N][M];
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}