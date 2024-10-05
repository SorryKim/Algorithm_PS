#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        int K;
        cin >> K;

        vector<int> v(K);
        vector<long long> sum(K + 1, 0);

        for(int i = 0; i < K; i++){
            cin >> v[i];
            // 누적합 기록
            sum[i + 1] = sum[i] + v[i];
        }

        // dp[start][end]: start ~ end구간이 합쳐지는 최소값
        vector<vector<long long>> dp(K, vector<long long>(K, 0));

        for(int len = 2; len <= K; len++){
            for(int start = 0; start <= K - len; start++){
                int end = start + len - 1;
                dp[start][end] = LLONG_MAX;
                for(int k = start; k < end; k++){
                    int val = sum[end + 1] - sum[start]; // 구간의 합
                    dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + val);
                }
            }
        }

        cout << dp[0][K - 1] << '\n';
    }

    return 0;
}
