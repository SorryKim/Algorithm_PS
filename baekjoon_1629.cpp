// 곱셉 / baekjoon_1629
// https://www.acmicpc.net/problem/1629

#include <iostream>
using namespace std;

long long calc(long long a, long long b,long long c) {

	if (b == 1) {
		return a % c;
	}

	// n이 짝수인 경우 a^n = a^(n/2) * a^(n/2)
	// n이 홀수인 경우 a^n = a^(n/2) * a^(n/2) * a 로 표현이 가능
	// 즉, 지수법칙을 사용하면 시간 복잡도를 O(log n)으로 낮출 수 있다.
	else {

		long long num = calc(a, b / 2, c);
		// b가 짝수인 경우
		if (b % 2 == 0) {
			return ((num%c) * (num%c)) % c;
		}
		// b가 홀수인 경우
		else {
			return (((num * num) % c) * (a % c))%c;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long a, b, c, result;
	cin >> a >> b >> c;

	result = calc(a, b, c);

	cout << result;
}
