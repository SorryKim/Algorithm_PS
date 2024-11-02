#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    
    cin >> T;

    while (T--) {

        int K, N;
        cin >> K >> N;
        vector<long long> dp(220, 0);
        
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= K; i++){
            for(int j = 210; j >= 0; j--){
                for(int k = 1; k <= i; k++)
                    dp[j + k] += dp[j];
            }
        }

        cout << dp[N] << '\n';
    }

    return 0;
}
