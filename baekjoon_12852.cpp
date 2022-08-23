// 1로 만들기 2/ baekjoon_12852.cpp
// https://www.acmicpc.net/problem/12852

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
// arr: 연산 전 위치
int dp[1000001];
int arr[1000001];

void input() {
    cin >> N;
}

void solve() {

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {

        dp[i] = dp[i - 1] + 1;
        arr[i] = i - 1;

        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                arr[i] = i / 3;
            }
        }

        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                arr[i] = i / 2;
            }
        }
    }

    cout << dp[N] << "\n";

    while (N != 0) {
        cout << N << " ";
        N = arr[N];
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();

}
