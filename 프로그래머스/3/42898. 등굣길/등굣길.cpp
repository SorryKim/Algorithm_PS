#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MOD = 1000000007;
int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    // 물에 잠긴 지역 표시
    for (auto& a : puddles) {
        dp[a[0]][a[1]] = -1;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            
            // 물에 잠긴 경우
            if (dp[i][j] == -1) {
                dp[i][j] = 0;  
            } else {
                if (i > 1) 
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 1) 
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    
    answer = dp[m][n];
    return answer;
}