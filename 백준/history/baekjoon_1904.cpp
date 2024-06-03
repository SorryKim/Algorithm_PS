// 01타일 / baekjoon_1904.cpp
// https://www.acmicpc.net/problem/1904

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int dp[1000001] = { 0, };
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	// (a+b)%c = (a%c + b%c)%c 모듈러 공식사용
	// dp[n-1]항에 1을붙이고 dp[n-2]에 00을 붙이면 dp[n]이 완성됨을 알 수 있다.
	// 점화식 dp[n] = dp[n-1] + dp[n-2]
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] % 15746 + dp[i - 2] % 15746) % 15746;
	}

	cout << dp[n];
}
