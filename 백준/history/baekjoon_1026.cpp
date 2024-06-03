// 보물 / baekjoon_1026.cpp
// https://www.acmicpc.net/problem/1026

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a,b;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(),compare);

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}

	cout << sum;
}
