// baekjoon_11055
// https://www.acmicpc.net/problem/11053

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0 };
int sum[1001] = { 0 };

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

	sum[0] = arr[0];
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				sum[i] = max(sum[j] + arr[i], sum[i]);
			}
		}
		result = max(result, sum[i]);
	}

	cout << result;

}
