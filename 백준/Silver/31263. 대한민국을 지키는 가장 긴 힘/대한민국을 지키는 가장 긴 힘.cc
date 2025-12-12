#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    if (!(cin >> N)) return 0;
    cin >> S;

    const int INF = 1e9;
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        if (dp[i] == INF) continue; 
        if (S[i] == '0') continue;
        
        int value = 0;
        for (int len = 1; len <= 3; ++len) {
            int j = i + len;
            if (j > N) break;

            value = value * 10 + (S[i + len - 1] - '0');
            if (value < 1 || value > 641) break;// 더 길어지면 더 커질 뿐이므로 중단

            dp[j] = min(dp[j], dp[i] + 1);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}
