#include <iostream>
#include <vector>
using namespace std;

int T, K;
vector<pair<int, int>> coins;

void input(){   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T >> K;
    coins.resize(K);
    for (int i = 0; i < K; i++) cin >> coins[i].first >> coins[i].second;
}

int solve(){
    vector<int> dp(T + 1, 0);
    dp[0] = 1;

    for (auto coin : coins) {

        int value = coin.first;
        int count = coin.second;

        for(int i = T; i >= 0; i--){
            for(int j = 1; j <= count; j++){
                int next = i + value * j;
                if(next > T) break;
                dp[next] += dp[i];
            }
        }
    }
    
    return dp[T];
}

int main() {
    input();
    cout << solve() << "\n";
    return 0;
}
