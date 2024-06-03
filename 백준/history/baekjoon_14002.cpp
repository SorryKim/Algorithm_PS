// 가장 긴 증가하는 부분 수열 4 / baekjoon_14002.cpp
// https://www.acmicpc.net/problem/14002

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int N;
int arr[1001];
int dp[1001];
stack<int> answer;

void input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

}

void solve() {

	int result = 0;
	int index = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		if (result < dp[i]) {
			result = dp[i];
			index = i;
		}
	}

	answer.push(arr[index]);

	for(int i = 0; i < result; i++){
		for (int j = index - 1; j >= 0; j--){
			if (arr[index] > arr[j]){
				// 오름차순으로 증가한 경우
				if (dp[index] == (dp[j] + 1)) {
					answer.push(arr[j]);
					index = j;
					break;
				}
			}
		}
	}

	
	cout << result << "\n";
	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}
