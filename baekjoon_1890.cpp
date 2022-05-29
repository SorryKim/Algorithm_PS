// 점프 / baekjoon_1890.cpp
// https://www.acmicpc.net/problem/1890

#include <iostream>
using namespace std;

int arr[101][101];
long long dp[101][101] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 마지막 항이 0이므로 x,y의 값이 N이하가 되어 값을 2번더 더하게 된다
			if (i == N && j == N)
				continue;
			int num = arr[i][j];
			int x = num + i;
			int y = num + j;
			if (x <= N)
				dp[x][j] += dp[i][j];
			if (y <= N)
				dp[i][y] += dp[i][j];

		}
	}

	cout << dp[N][N];
}
