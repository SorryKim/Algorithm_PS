// 로프 / baekjoon_2217.cpp
// https://www.acmicpc.net/problem/2217

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> v;
	int result = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		int temp = v[i] * (N - i);
		result = max(result, temp);
	}

	cout << result;
}
