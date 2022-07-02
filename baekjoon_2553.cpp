// 마지막 팩토리얼 수 / baekjoon_2553.cpp
// https://www.acmicpc.net/problem/2553

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	long long result = 1;

	for (int i = 1; i <= n; i++) {

		result *= i;
		result %= 100000000; // 수 제한, 1억

		// 끝자리수가 0이면 버림
		while ((result % 10) == 0) {
			result /= 10;
		}
	}

	cout << (result % 10);

}
