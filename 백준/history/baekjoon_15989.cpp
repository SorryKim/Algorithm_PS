// 1, 2, 3 더하기 4 / baekjoon_15989.cpp
// https://www.acmicpc.net/problem/15989

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dp[10001][4];

void Input() {
    
    cin >> n;
  
}


void Solve() {

    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;

    for (int i = 3; i <= 10000; i++) {
        
        // 마지막이 1
        dp[i][1] = dp[i - 1][1];
        // 마지막이 2
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        // 마지막이 3
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        Input();
        Solve();
    }
    
}
