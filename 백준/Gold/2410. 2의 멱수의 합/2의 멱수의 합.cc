#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int DIV = 1000000000;
    int N;
    cin >> N;

    vector<int> dp(N + 1);
    vector<int> nums;

    for(int num = 1; num <= N; num *= 2) nums.push_back(num);
    dp[0] = 1;

    for(int num : nums){
        for(int i = num; i <= N; i++){
            dp[i] = (dp[i] + dp[i - num]) % DIV;
        }
    }

    cout << dp[N] << '\n';
    
    return 0;
}