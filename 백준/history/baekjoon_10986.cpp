// 나머지 합 / baekjoon_10986.cpp
// https://www.acmicpc.net/problem/10986

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
long long arr[1000000];

void Input() {

}

void Solve() {

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	long long sum = 0;
	long long result = 0;

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		sum += num;

		result += arr[sum % M];
		arr[sum % M] += 1;
	}

	cout << result + arr[0];
}
