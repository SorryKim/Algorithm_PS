#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D;
int graph[16][16];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long dp[36];

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for(int i = 4; i <= 35; i++){
        dp[i] = 0;
        for(int j = 0; j < i; j++){
            dp[i] += dp[j]*dp[i - j - 1];
        }
    }

    cout << dp[N];

    return 0;
}
