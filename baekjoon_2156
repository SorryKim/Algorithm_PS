// baekjoon_2156
// https://www.acmicpc.net/problem/2156

#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001] = { 0 };
int sum[10001] = { 0 };



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	sum[1] = arr[1];
	sum[2] = sum[1] + arr[2];
	int v1 = max(arr[1] + arr[2], arr[1] + arr[3]);
	int v2 = max(arr[2] + arr[3], v1);
	sum[3] = v2;
	for (int i = 4; i <= n; i++) {
		int value1 = max(sum[i - 2] + arr[i], sum[i - 3] + arr[i - 1] + arr[i]);
		int value2 = max(value1, sum[i - 1]);
		sum[i] = value2;
	}

	cout << sum[n] << "\n";
	
}
