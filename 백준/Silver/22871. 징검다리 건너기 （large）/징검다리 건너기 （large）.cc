#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    const long long INF = 1e15;
    vector<long long> dp(N, INF);
    dp[0] = 0;

    for (int j = 1; j < N; j++) {
        for (int i = 0; i < j; i++) {
            long long cost = (long long)(j - i) * (1 + abs(A[i] - A[j]));
            dp[j] = min(dp[j], max(dp[i], cost));
        }
    }

    cout << dp[N - 1] << "\n";
    return 0;
}
