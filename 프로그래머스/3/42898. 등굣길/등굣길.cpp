#include <string>
#include <vector>

using namespace std;

long long MOD = 1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    for(auto a : puddles) dp[a[0]][a[1]] = -1;
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            
            // -1로 놔두면 dp 값 이상해짐
            if(dp[i][j] == -1) dp[i][j] = 0;
            else{
                if(i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if(j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    
    return dp[m][n];
}