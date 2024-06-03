// 안녕 / baekjoon_1535.cpp
// https://www.acmicpc.net/problem/1535

#include <iostream>
using namespace std;

int N;
int happy[21];
int hp[21];
int dp[100];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> hp[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> happy[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	for (int i = 1; i <= N; i++) {
		for (int j = 100; j > hp[i]; j--) {
			dp[j] = max(dp[j], dp[j - hp[i]] + happy[i]);
		}
	}

	cout << dp[100];
}
