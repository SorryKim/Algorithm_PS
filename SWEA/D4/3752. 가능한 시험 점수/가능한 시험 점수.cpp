#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    for(int T = 1; T <= TC; T++){

        int N;
        cin >> N;
        int ans = 0, sum = 0;
        vector<int> scores;
        for(int i = 0; i < N; i++){
            int n;
            cin >> n;
            scores.push_back(n);
            sum += n;
        }

        vector<bool> dp(sum + 1, false);
        dp[sum] = true;

        for(int score : scores){
            for(int i = 0; i <= sum; i++){
                if(dp[i] && i - score >= 0){
                    dp[i - score] = true;
                }
            }
        }

        for(bool b : dp){
            //cout << b << " ";
            if(b) ans++;
        }

        cout << "#" << T << " " << ans << "\n";
    }

    return 0;
}