// baekjoon_9095
// https://www.acmicpc.net/submit/9095

#include <iostream>
#include <algorithm>
using namespace std;

int arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	arr[4] = 7;
	for (int i = 5; i <= 10; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int num;
		cin >> num;
		cout << arr[num] << "\n";
	}
}
