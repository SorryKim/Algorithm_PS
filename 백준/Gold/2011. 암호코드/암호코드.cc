#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000;
int N;
int dp[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    N = s.size();
    dp[N] = 1;

    for (int i = N - 1; i >= 0; i--) {
        
        int now = s[i] - '0';

        if (now == 0) {
            dp[i] = 0;
            continue;
        }

        // 한 자리 수 해석 가능
        dp[i] = dp[i + 1];

        // 두 자리 수 해석 가능 여부 확인
        if (i + 1 < N) {
            int next = now * 10 + (s[i + 1] - '0');
            if (next >= 10 && next <= 26) {
                dp[i] = (dp[i] + dp[i + 2]) % MOD;
            }
        }
    }


    cout << dp[0];

    return 0;
}