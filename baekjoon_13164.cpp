// 행복 유치원 / baekjoon_13164.cpp
// https://www.acmicpc.net/problem/13164

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, result;
vector<int> v;

void Input() {
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {

		int num;
		cin >> num;
		v.push_back(num);
	}
	
}


void Solve() {

	sort(v.begin(), v.end());
	result = v[N - 1] - v[0];


	for (int i = N - 1; i >= 1; i--) {
		v[i] = v[i] - v[i - 1];
	}

	v[0] = 0;
	sort(v.begin(), v.end());

	for (int i = N - 1; K > 1; i--) {
		result -= v[i];
		K--;
	}

	cout << result << "\n";
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
