#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    const int MOD = 1000000000 + 7;
    cin >> N;

    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));

    // [N][0]: 둘 중 한명이 현이에게 듣는 경우
    // [N][1]: 둘 다 현이에게 듣는 경우
    dp[1][0] = 2;
    dp[1][1] = 1;
    

    for(int i = 2; i <= N; i++){

        // 전 줄은 둘다 현이에게 들어도 됨
        dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) * 2) % MOD;
        
        // 전 줄은 둘 중 한명이 현이에게 들어야함
        dp[i][1] = dp[i - 1][0];
    }

    long long ans = (dp[N][0] + dp[N][1]) % MOD;
    cout << ans << "\n";
}