// 연속합 2 / baekjoon_13398.cpp
// https://www.acmicpc.net/problem/13398

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result;
vector<int> v;
int dp[100001][2];

void Input() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

}

void Solve() {
	
	result = v[0];

	// 수 제거 x
	dp[0][0] = v[0];
	// 수 1개 제거했을 때 가장 큰 경우
	dp[0][1] = v[0];

	for (int i = 1; i < n; i++) {

		dp[i][0] = max(dp[i - 1][0] + v[i], v[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);

		result = max(result, max(dp[i][0], dp[i][1]));
	}

	cout << result;
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
}
