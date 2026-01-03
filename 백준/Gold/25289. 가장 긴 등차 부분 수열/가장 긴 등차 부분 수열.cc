#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    v.resize(N, 0);
    for(int i = 0; i < N; i++) cin >> v[i];
}

int solve() {
    
    vector<vector<int>> dp(101, vector<int>(201, 0));
    vector<int> seen(101, 0);

    int ans = 1;

    for (int idx = 0; idx < N; idx++) {
        int now = v[idx];

        vector<int> next(201, 0);

        for (int prev = 1; prev <= 100; prev++) {
            if (seen[prev] == 0) continue;

            int nd = (now - prev) + 100;
            if (nd < 0 || nd > 200) continue;

            // prev -> now 로 새로 시작하면 길이 2
            next[nd] = max(next[nd], 2);

            // 기존 공차 nd 수열에 now를 붙이면
            if (dp[prev][nd] > 0) next[nd] = max(next[nd], dp[prev][nd] + 1);
            
            ans = max(ans, next[nd]);
        }

        // now로 끝나는 dp 갱신
        for (int d = 0; d <= 200; d++) dp[now][d] = max(dp[now][d], next[d]);
    
        // 이제 now가 등장했음을 기록
        seen[now]++;
    }

    return ans;
}




int main(){

    input();
    cout << solve() << "\n";

    return 0;
}