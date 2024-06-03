// 통나무 건너뛰기/ baekjoon_11497.cpp
// https://www.acmicpc.net/problem/11497

#include <iostream>
#include <algorithm>
using namespace std;

int T;
int arr[10001];

void Input() {
	cin >> T;
}


void Solve(int N) {

	sort(arr, arr + N);

	int result = 0;

	for (int i = 0; i < N - 2; i++) 
		result = max(arr[i + 2] - arr[i], result);
	
	
	cout << result << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	Input();
	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) 
			cin >> arr[i];
		Solve(N);
	}
	
}
