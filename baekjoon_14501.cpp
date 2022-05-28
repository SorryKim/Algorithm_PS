// 퇴사 / baekjoon_14501.cpp
// https://www.acmicpc.net/problem/14501

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[20][2];
	int dp[20] = { 0, };

	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1]; // 소요 시간, 비용
	}

	for (int i = N; i >= 1; i--) {
		int time = arr[i][0];
		int value = arr[i][1];
		int endTime = time + i;

		// 상담가능한 경우
		if (endTime <= N + 1) {
			dp[i] = max(dp[i + 1], dp[endTime] + value);
		}

		// 상담 불가능한 경우
		else {
			dp[i] = dp[i + 1];
		}
	}
	
	
	cout << dp[1];
	
}
