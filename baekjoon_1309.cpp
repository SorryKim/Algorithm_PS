// 동물원 / baekjoon_1309.cpp
// https://www.acmicpc.net/problem/1309

#include <iostream>
using namespace std;

int dp[100000][3] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// dp[n][0] => n행에 사자를 놓지 않는 경우
	// dp[n][1] => n행에 오른쪽에 사자를 놓는 경우
	// dp[n][2] => n행에 왼쪽에 사자를 놓는 경우
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;

	// dp[n][0] => n-1항이 0,1,2 가능
	// dp[n][1] => n-1항이 0,1 가능
	// dp[n][2] => n-1항이 0,2 가능

	for (int i = 1; i < N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	int result = (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % 9901;
	cout << result;
}
