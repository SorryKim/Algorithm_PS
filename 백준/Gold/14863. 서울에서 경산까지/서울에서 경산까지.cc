#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> walk[101];
pair<int, int> bike[101];

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        walk[i] = {a, b};
        bike[i] = {c, d};
    }
}

int solve() {
    int ans = 0;

    // dp[j] = j분을 써서 얻을 수 있는 최대 모금액
    vector<int> dp(K + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {

        vector<int> next(K + 1, -1);

        int wt = walk[i].first;
        int wm = walk[i].second;
        int bt = bike[i].first;
        int bm = bike[i].second;

        for (int t = 0; t <= K; t++) {
            if (dp[t] == -1) continue;

            // 도보 선택
            if (t + wt <= K)
                next[t + wt] = max(next[t + wt], dp[t] + wm);

            // 자전거 선택
            if (t + bt <= K)
                next[t + bt] = max(next[t + bt], dp[t] + bm);
        }

        dp = next;
    }

    for (int i = 0; i <= K; i++) ans = max(ans, dp[i]);
    return ans;
}

int main() {
    input();
    cout << solve() << "\n";
    return 0;
}
