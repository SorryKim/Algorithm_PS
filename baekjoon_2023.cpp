// 신기한 소수 / baekjoon_2023.cpp
// https://www.acmicpc.net/problem/2023

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

// 소수 판정
bool check(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void DFS(int num, int depth) {

	// N자리인 경우
	if (depth == N) {
		cout << num << "\n";
		return;
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (check(num * 10 + i)) 
				DFS((num*10) + i, depth + 1);
		}
	}

}

void Input() {
	cin >> N;
}


void Solve() {

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Input();
	Solve();
}
