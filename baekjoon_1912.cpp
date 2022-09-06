// baekjoon_1912
// https://www.acmicpc.net/problem/1912

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001] = { 0 };
int sum[100001] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		sum[i] = num;
	}
	int result = -2147483648;
	for (int i = 1; i <= N; i++) {
		if (arr[i] >= 0) {
			if (sum[i - 1] < 0)
				sum[i] = arr[i];
			else
				sum[i] = sum[i-1] + arr[i];
		}
		else {
			sum[i] = max(arr[i],sum[i - 1] + arr[i]);
		}
		result = max(result, sum[i]);
	}

	cout << result;
;
}
