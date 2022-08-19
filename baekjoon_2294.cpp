// 동전 2 / baekjoon_2294.cpp
// https://www.acmicpc.net/problem/2294

#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int coin[101];
int DP[10001];
#define INF 987654321

void input() {
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }

    for (int i = 0; i <= 10000; i++) {
        DP[i] = INF;
    }

}

void solve() {

    DP[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
           DP[j] = min(DP[j], DP[j - coin[i]] + 1);
        }
    }

    if (DP[k] == INF)
        cout << -1;
    else
        cout << DP[k];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

}
