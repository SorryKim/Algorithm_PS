#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100999;
const int MAX = 2000;

int T;
vector<int> dp(MAX + 1, 0);

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
}

void solve(){

    dp[0] = 1;

    // 1~2000까지의 수를 한 번씩만 사용
    for(int i = 1; i <= MAX; i++){
        for(int j = MAX; j >= i; j--){
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    

}

int main() {
    
    input();
    solve();

    while(T--){
        int N;
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}
