// 가장 긴 증가하는 부분 수열 5 / baekjoon_14003.cpp
// https://www.acmicpc.net/problem/14003

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int N;
int dp[1000001];
int arr[1000001];
vector<int> v;
stack<int> answer;

void input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
}

void print() {
	cout << v.size() << "\n";
	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}
}

void solve() {
	

	for (int i = 0; i < N; i++) {
		if (v.size() == 0 || arr[i] > v.back()) {
			v.push_back(arr[i]);
			dp[i] = v.size()-1;
		}
		else {
			int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[index] = arr[i];
			dp[i] = index;
		}
	}

	int temp = v.size() - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == temp) {
			temp--;
			answer.push(arr[i]);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	print();
}
