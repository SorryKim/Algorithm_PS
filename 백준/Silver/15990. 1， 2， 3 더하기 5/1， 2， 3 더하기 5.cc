#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int DIV = 1000000009;
long long dp[100001][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;
    cin >> TC;

    // [숫자][끝나는 숫자]
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    dp[2][3] = 0;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    for(int i = 4; i <= 100000; i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % DIV;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % DIV;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % DIV;
    }

    while(TC--){
        int n;
        cin >> n;

        long long answer = (dp[n][1] + dp[n][2] + dp[n][3]) % DIV;
        cout << answer << '\n';
    }
}
