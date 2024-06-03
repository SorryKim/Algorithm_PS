// 알약 / baekjoon_4811.cpp
// https://www.acmicpc.net/problem/4811

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long dp[31][31];

void Clear() {

    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++)
            dp[i][j] = 0;
    }

    for (int i = 0; i <= 30; i++)
        dp[0][i] = 1;

}

void Input() {
    
    cin >> N;

}

void Solve() {

    // dp테이블 초기화
    Clear();

    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {

            // 첫날, 무조건 1개짜리 나옴
            if (j == 0)
                dp[i][0] = dp[i - 1][1];

            else
                dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
        }
    }


    cout << dp[N][0] << "\n";
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    N = 1;
    while (N != 0) {
        Input();
        if (N == 0)
            break;
        Solve();
    }
}
