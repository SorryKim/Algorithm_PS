// 가장 긴 바이토닉 부분 수열 / baekjoon_11054.cpp
// https://www.acmicpc.net/problem/11054

#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001][2];

void input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
}

void solve() {

	// 증가하는 수열
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}

	// 감소하는 수열
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}

	// 가장 최대지점 찾기
	int result = 0;
	for (int i = 0; i < N; i++) {
		result = max(result, dp[i][0] + dp[i][1]);
	}

	cout << result + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}
