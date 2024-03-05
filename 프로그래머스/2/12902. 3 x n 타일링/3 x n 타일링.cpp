#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MOD = 1000000007;
long long dp[2501] = { 0, };

int solution(int n) {
    int answer = 0;
    
    dp[1]  = 3;
    dp[2] = 11;
    for(int i = 3; i <= 2500; i++) {
        dp[i] = dp[i-1] * 3 + 2;
        
        for(int j = 1; j < i-1; j++)
            dp[i] += dp[j] * 2;
        
        dp[i] %= MOD;
    }
    
    cout << dp[3] << endl;
    cout << dp[4] << endl;
    
    // n이 홀수인 경우 0
    answer = n % 2 ? 0 : dp[n/2];
    return answer;
}