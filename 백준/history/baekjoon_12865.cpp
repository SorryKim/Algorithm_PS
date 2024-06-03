// 평범한 배낭 / baekjoon_12865
// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <algorithm>
using namespace std;

int value[101];
int weight[101];
int dp[101][100001]; // 무게별로 최대가치값 저장할 배열

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	// 물건 입력받기
	for (int i = 1; i <= N; i++) {
		int v, w;
		cin >> w >> v;
		value[i] = v;
		weight[i] = w;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			// 무게를 버틸 수 있는 경우
			if (j >= weight[i]) {
				// 이전가치랑, 현재가치랑 비교하여 큰 수를 dp에 저장
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]] + value[i]);
			}
			else {
				// 넣지 않는 경우
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[N][K];

}
