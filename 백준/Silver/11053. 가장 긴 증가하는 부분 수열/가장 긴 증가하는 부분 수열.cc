// baekjoon_11053
// https://www.acmicpc.net/problem/11053

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0 };
int result[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill_n(result, 1001, 1);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				result[i] = max(result[i], result[j] + 1);
			}
		}
		ans = max(ans, result[i]);
	}

	cout << ans;

}