#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; 

    while (T--) {
        int N, money;
        cin >> N;  
        vector<int> coins(N);
        for (int i = 0; i < N; i++) cin >> coins[i];
        cin >> money; 

        vector<int> dp(money + 1, 0);
        dp[0] = 1; 

		for(int coin : coins){
			for(int i = coin; i <= money; i++){
				dp[i] += dp[i - coin];
			}
		}
		
        cout << dp[money] << '\n';
    }

    return 0;
}
