// RGB거리 2 // baekjoon_17404.cpp
// https://www.acmicpc.net/problem/17404

#include <iostream>
using namespace std;

int N;
int result = 987654321;
int price[1001][3];
int dp[1001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력받기
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> price[i][0] >> price[i][1] >> price[i][2];
	}

	for (int i = 0; i < 3; i++) {
		
		// 1번째 집의 색상 결정
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				dp[0][j] = price[0][j];
			}
			else {
				dp[0][j] = 9876654321;
			}
		}

		// dp
		for (int j = 1; j < N; j++) {
			dp[j][0] = price[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = price[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = price[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		// 1번째와 N번째 집이 같지 않게 체크
		for (int j = 0; j < 3; j++) {
			if (i == j)
				continue;
			else {
				result = min(result, dp[N - 1][j]);
			}
		}
	}

	cout << result;

}
