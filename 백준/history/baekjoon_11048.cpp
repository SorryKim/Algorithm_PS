// 이동하기 / baekjoon_11048.cpp
// https://www.acmicpc.net/problem/11048

#include <iostream>
using namespace std;

int dp[1010][1010] = { 0, };
int map[1010][1010];
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 값 입력받기
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + map[i][j];
		}
	}

	cout << dp[N][M];
	return 0;
}
