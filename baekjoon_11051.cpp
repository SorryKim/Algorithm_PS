// 이항 계수 2 / baekjoon_11051.cpp
// https://www.acmicpc.net/problem/11051

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int dp[1001][1001] = { 0, };
	int N, K;
	cin >> N >> K;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (j == 0)
				dp[i][j] = 1;
			else if (j == i)
				dp[i][j] = 1;
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
			}
		}
	}

	cout << dp[N][K];
}
