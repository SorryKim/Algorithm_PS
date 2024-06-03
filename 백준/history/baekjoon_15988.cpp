// 1, 2, 3 더하기 3 / baekjoon_15988.cpp
// https://www.acmicpc.net/problem/15988

#include<iostream>
using namespace std;

int n;
long long dp[1000001];
#define DIV 1000000009;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= 1000000; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % DIV;
    }

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] % DIV;
        cout << "\n";
    }

}
