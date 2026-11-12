#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int N = sticker.size();
    int dp[100000][2] = {0};
    if(N == 1) return sticker[0];
    
    // 1. 첫번째 원소 선택
    dp[0][0] = 0;
    dp[0][1] = sticker[0];
    
    for(int i = 1; i < N - 1; i++){
        
        // 선택
        dp[i][1] = dp[i - 1][0] + sticker[i];
        
        // 선택x
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
    }
    
    answer = max(dp[N -  2][0], dp[N - 2][1]);
    
    // 2. 첫번째 선택x
    dp[0][0] = 0;
    dp[0][1] = 0;
    
     for(int i = 1; i < N; i++){
        
        // 선택
        dp[i][1] = dp[i - 1][0] + sticker[i];
        
        // 선택x
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
    }
    
    answer = max(answer, max(dp[N - 1][0], dp[N - 1][1]));
    
    return answer;
}