// LCS 2  / baekjoon_9252.cpp
// https://www.acmicpc.net/problem/9252

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	
	int N = s1.length();
	int M = s2.length();
	vector<vector<int>> dp;
	vector<char> lcs;
	dp.resize(N + 1, vector<int>(M + 1, 0));

	for (int i = 1; i <= N; i++) {
		// lcs의 길이
		for (int j = 1; j <= M; j++) {
			// 같은 경우
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			// 다른 경우
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// 백트래킹하면서 lcs 체크
	bool end = false;
	int temp = N;
	for (int j = M; j >= 0; j--) {
		for (int i = temp; i >= 0; i--) {
			if (dp[i][j] == 0) {
				end = true;
				break;
			}
			if (dp[i][j] == dp[i][j - 1])
				break;
			else if (dp[i][j] == dp[i - 1][j])
				continue;
			else {
				lcs.push_back(s1[i - 1]);
				temp = i - 1;
				break;
			}
		}
		if (end)
			break;
	}


	// 결과 출력
	cout << dp[N][M] << '\n';
	while (!lcs.empty()) {
		cout << lcs.back();
		lcs.pop_back();
	}
	
	return 0;
}
