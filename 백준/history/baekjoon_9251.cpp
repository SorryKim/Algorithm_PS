// LCS / baekjoon_9251.cpp
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int DP[1001][1001] = { 0, };
	string s1, s2;
	cin >> s1 >> s2;

	
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			// 같은 문자가 나올 시 전항에 1을 더하여 저장
			if (s1[i - 1] == s2[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			// 아닐 시 이전 항 중 최대값을 저장
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	cout << DP[s1.size()][s2.size()];

	return 0;
}
