// Dance Dance Revolution / baekjoon_2342.cpp
// https://www.acmicpc.net/problem/2342

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int dp[100001][5][5];
int result;

void Input() {

	int num;
	result = 0;

	while (true) {
		cin >> num;
		if (num == 0)
			break;
		v.push_back(num);
	}

	for (int i = 0; i <= 100000; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = 0;
			}
		}
	}

}

// a에서 b로 가는 힘을 구하는 함수
int Calc(int a, int b) {

	switch (a) {
	case 0:
		return 2;
	case 1:
		if (b == 0)
			return 2;
		if (b == 1)
			return 1;
		if (b == 2)
			return 3;
		if (b == 3)
			return 4;
		if (b == 4)
			return 3;
	case 2:
		if (b == 0)
			return 2;
		if (b == 1)
			return 3;
		if (b == 2)
			return 1;
		if (b == 3)
			return 3;
		if (b == 4)
			return 4;
	case 3:
		if (b == 0)
			return 2;
		if (b == 1)
			return 4;
		if (b == 2)
			return 3;
		if (b == 3)
			return 1;
		if (b == 4)
			return 3;
	case 4:
		if (b == 0)
			return 2;
		if (b == 1)
			return 3;
		if (b == 2)
			return 4;
		if (b == 3)
			return 3;
		if (b == 4)
			return 1;
	}
}

int DFS(int n, int a, int b) {

	if (n == v.size())
		return 0;

	if (dp[n][a][b] != 0)
		return dp[n][a][b];

	int left = Calc(a, v[n]) + DFS(n + 1, v[n], b);
	int right = Calc(b, v[n]) + DFS(n + 1, a, v[n]);
	dp[n][a][b] = min(left, right);

	return dp[n][a][b];

}


void Solve() {

	cout << DFS(0, 0, 0);

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Input();
	Solve();
}
