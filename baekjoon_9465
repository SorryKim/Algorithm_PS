// baekjoon_9465
// https://www.acmicpc.net/problem/9465

#include <iostream>
#include <algorithm>
using namespace std;

int sum[2][100001] = { 0 };
int value[2][100001] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;

	for (int test = 0; test < T; test++) {
		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			int n;
			cin >> n;
			value[0][i] = n;
		}
		for (int i = 0; i < num; i++) {
			int n;
			cin >> n;
			value[1][i] = n;
		}
		sum[0][0] = value[0][0];
		sum[1][0] = value[1][0];
		sum[0][1] = sum[1][0] + value[0][1];
		sum[1][1] = sum[0][0] + value[1][1];

		for (int i = 2; i < num; i++) {
			sum[0][i] = value[0][i] + max(sum[1][i - 1], sum[1][i - 2]);
			sum[1][i] = value[1][i] + max(sum[0][i - 1], sum[0][i - 2]);
		}
		cout << max(sum[0][num - 1], sum[1][num - 1]) << "\n";
	}
}
