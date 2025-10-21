#include <iostream>
#include <vector>
using namespace std;

const int MOD = 16769023;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // dp[d+1] (index: 0→-1, 1→0, 2→+1)
    vector<int> dp(3, 0), nxt(3, 0);

    // 초기값
    dp[2] = 1; // d = +1
    dp[1] = 0; // d =  0
    dp[0] = 1; // d = -1

    for (int i = 2; i <= N; i++) {
        nxt[2] = dp[1] % MOD;                 
        nxt[1] = (dp[2] + dp[0]) % MOD;
        nxt[0] = dp[1] % MOD;                 
        dp = nxt;
    }

    int ans = (dp[0] + dp[1] + dp[2]) % MOD;
    cout << ans << "\n";
    return 0;
}
