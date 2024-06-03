// 상자넣기 / baekjoon_1965.cpp
// https://www.acmicpc.net/problem/1965

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[1010] = { 0, };
	int dp[1010] = { 0, };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int max = 0;

	// LIS 방법
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {

			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) 
			max = dp[i];
	}

	cout << max;
}
