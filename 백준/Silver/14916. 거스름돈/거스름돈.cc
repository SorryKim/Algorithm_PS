#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int INF = 1e9;
    int N;
    cin >> N;
    vector<int> dp(N + 1, INF);
    
    dp[2] = 1;
    dp[5] = 1;

    for(int i = 1; i <= N; i++){

        int a = i - 2; // 2원짜리 추가하는 경우
        int b = i - 5; // 5원짜리 추가하는 경우

        if(a > 0) if(dp[a] != INF) dp[i] = min(dp[i], dp[a] + 1);
        if(b > 0) if(dp[b] != INF) dp[i] = min(dp[i], dp[b] + 1);
        
    }


    if(dp[N] < 1 || dp[N] == INF) cout << -1 << '\n';
    else cout << dp[N] << '\n';
    
    return 0;
}
