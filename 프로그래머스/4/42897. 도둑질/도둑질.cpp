#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    vector<int> dp(N, 0);
    
    // 1. 첫번째 집을 털음
    dp[0] = money[0];
    dp[1] = money[0];
    
    for(int i = 2; i < N - 1; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    
    answer = dp[N - 2];
    
    // 2. 첫집안털음
    dp[0] = 0;
    dp[1] = money[1];
    
    for(int i = 2; i < N; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    
    answer = max(answer, dp[N - 1]);
    
    
    return answer;
}