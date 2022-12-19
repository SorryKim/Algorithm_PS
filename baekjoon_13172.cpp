// Σ / baekjoon_13172.cpp
// https://www.acmicpc.net/problem/13172

#include <iostream>
using namespace std;

long long MOD = 1000000007;

long long func(long long x, long long y) {

	if (y == 1)
		return x;

	if ((y % 2) == 1)
		return x * func(x, y - 1) % MOD;

	long long p = func(x, y / 2);

	return p * p % MOD;
}

long long gcd(long long x, long long y) {

	long long temp;

	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}

	long long rest;
	while (y != 0) {
		rest = x % y;
		x = y;
		y = rest;
	}

	return x;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long m, a, b;
	long long result = 0;

	cin >> m;

	while (m--) {
		cin >> a >> b;
		long long temp = gcd(a, b);
		b /= temp;
		a /= temp;
		result += b * func(a, MOD - 2) % MOD;
		result %= MOD;
	}

	cout << result << "\n";


}
