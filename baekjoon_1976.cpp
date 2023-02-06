// 여행 가자 / baekjoon_1976.cpp
// https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int parent[201];
bool trip[201];

int Find(int n) {
	
	if (parent[n] == n)
		return n;

	return parent[n] = Find(parent[n]);
}

void Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	parent[n1] = n2;
	Find(n1);
}

void Input() {
	
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	// 길이 있는경우 UNION연산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			if (num == 1)
				Union(i, j);
		}
	}

}


void Solve() {
	
	int temp;
	cin >> temp;

	bool b = true;

	// FIND를 통해 부모를 비교
	for (int i = 1; i < M; i++) {

		int now;
		cin >> now;

		if (!b)
			continue;

		if (Find(temp) != Find(now)) {
			b = false;
			break;
		}

		temp = now;
	}

	// 결과출력
	b ? cout << "YES" << "\n" : cout << "NO" << "\n";

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Input();
	Solve();
}
