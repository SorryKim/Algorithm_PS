// 게임 / baekjoon_1072.cpp
// https://www.acmicpc.net/problem/1072

#include <iostream>
#include <algorithm>
#define MAX 1000000000;
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long x, y;
	cin >> x >> y;

	long long z = (100 * y) / x;

	if (z >= 99) {
		cout << -1;
		return 0;
	}

	long long low = 0;
	long long high = MAX;
	long long result = 0;

	// 이분 탐색을 사용해야 시간초과가 나지 않는다.
	while (low <= high) {

		long long mid = (low + high) / 2;
		long long temp = (100 * (y + mid)) / (x + mid);

		if (z < temp)
			high = mid - 1;

		else {
			low = mid + 1;
			result = mid + 1;
		}
	}
	

	cout << result << "\n";
}
