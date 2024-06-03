// 스도쿠 / baekjoon_2580.cpp
// https://www.acmicpc.net/problem/2580

#include <iostream>
using namespace std;
int sudoku[9][9] = { 0, };

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
		}
	}
}

void output() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
}

bool check(int x, int y, int val) {

	// check row, col
	for (int i = 0; i < 9; i++) {
		if (sudoku[x][i] == val)
			return false;
		if (sudoku[i][y] == val)
			return false;
	}

	// check square
	int startX = (x / 3) * 3;
	int startY = (y / 3) * 3;
	for (int i = startX; i < startX + 3; i++) {
		for (int j = startY; j < startY + 3; j++) {
			if (sudoku[i][j] == val)
				return false;
		}
	}

	return true;
}

void solve(int x, int y) {

	if (x == 9) {
		output();
		exit(0);
	}

	if (y == 9) {
		solve(x + 1, 0);
	}

	if (sudoku[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			// 백트래킹
			if (check(x, y, i)) {
				sudoku[x][y] = i;
				solve(x, y + 1);
				sudoku[x][y] = 0;
			}
		}
	}
	else
		solve(x, y + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve(0, 0);
}
