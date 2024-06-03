// 기타리스트 / baekjoon_1495.cpp
// https://www.acmicpc.net/problem/1495

#include <iostream>
#include <vector>
using namespace std;

int N, S, M;
int arr[51];
bool dp[51][1001] = {false, };

void input() {
	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) 
		cin >> arr[i];
}

void solve() {

	int start = S;
	dp[0][S] = 1;

 	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {

			if (dp[i - 1][j]) {

				// 음을 올리는 경우
				if (j + arr[i] <= M) {
					dp[i][j + arr[i]] = true;
				}
				
				// 음을 내리는 경우
				if (j - arr[i] >= 0) {
					dp[i][j - arr[i]] = true;
				}
			}
		}
	}

	int result = -1;

	for (int i = 0; i <= M; i++) {
		if (dp[N][i])
			result = max(result, i);
	}

	cout << result << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	
}