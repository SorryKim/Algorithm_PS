#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<long long> dp(68, 0);

    dp[0] = 1;
    dp[1] = 1; 
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= 67; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    while(T--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}