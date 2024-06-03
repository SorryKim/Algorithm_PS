// 정수 삼각형 / baekjoon_1932.cpp
// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int tri[501][501] = { 0, };
int dp[501][501] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int num;
			cin >> num;
			tri[i][j] = num;
		}
	}

	dp[1][1] = tri[1][1];
	
	if (n > 1){
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);
			}
		}
		int result = dp[n][1];
		for (int i = 1; i <= n; i++) {
			if (dp[n][i] > result)
				result = dp[n][i];
		}

		cout << result;
		
	}
	else {
		cout << dp[1][1];
	}
}
