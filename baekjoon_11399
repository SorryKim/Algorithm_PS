// baekjoon_11399
// https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	stable_sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j <= i; j++) {
			sum += v[j];
		}
	}

	cout << sum;
}
