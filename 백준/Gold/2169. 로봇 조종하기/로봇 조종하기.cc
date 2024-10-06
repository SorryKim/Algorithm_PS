#include <iostream>
#include <vector>

using namespace std;

int N, M;
int graph[1001][1001];
int dp[1001][1001][2];
pair<int,int> move_dir[3] = {{1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> graph[i][j];
        }
    }

    dp[1][1][0] = graph[1][1];
    dp[1][1][1] = graph[1][1];


    // 1행에서는 무조건 오른쪽밖에 못감
    for(int i = 2; i <= M; i++){
        dp[1][i][0] = dp[1][i - 1][0] + graph[1][i];
        dp[1][i][1] = dp[1][i - 1][1] + graph[1][i];
    }

    for(int x = 2; x <= N; x++){

        // 밑으로 이동
        for(int y = 1; y <= M; y++){
            int var = max(dp[x - 1][y][0], dp[x - 1][y][1]) + graph[x][y];
            dp[x][y][0] = var;
            dp[x][y][1] = var;
        }

        // 왼쪽으로 가는 경우
        for(int y = 2; y <= M; y++){
            dp[x][y][0] = max(dp[x][y][0], dp[x][y - 1][0] + graph[x][y]);
        }

        // 오른쪽으로 가는 경우
        for(int y = M - 1; y >= 1; y--){
            dp[x][y][1] = max(dp[x][y][1], dp[x][y + 1][1] + graph[x][y]);
        }
        
    }
    
    int ans = max(dp[N][M][0], dp[N][M][1]);
    cout << ans;
    return 0;
}
