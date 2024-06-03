// 숫자고르기 / baekjoon_2668.cpp
// https://www.acmicpc.net/problem/2668

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[101], visit[101], result[101];
vector<int> v;

void Input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		visit[i] = 0;
		result[i] = 0;
	}
}

void DFS(int now, int start) {

	if (visit[now]) {
		if (now == start)
			v.push_back(start);
	}
	else {
		visit[now] = 1;
		DFS(arr[now], start);
	}

}

// 배열 초기화
void clear() {
	for (int i = 0; i <= N; i++)
		visit[i] = 0;
}

void Solve() {

	for (int i = 1; i <= N; i++) {
		clear();
		DFS(i, i);
	}

	// 결과출력
	cout << v.size() << "\n";
	for (auto a : v)
		cout << a << "\n";
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
