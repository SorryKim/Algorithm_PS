// 동전 1 / baekjoon_2293.cpp
// https://www.acmicpc.net/problem/2293

#include <iostream>
using namespace std;

int coin[101];
int dp[10001];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	} 

	cout << dp[k];
}
