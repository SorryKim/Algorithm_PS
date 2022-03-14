// baekjoon_1780
// https://www.acmicpc.net/problem/1780

#include <iostream>
using namespace std;

int paper[2200][2200];
int num1 = 0, num2 = 0, num3 = 0;

// 해당 범위 동안 같은 값을 갖는지 확인하는 메소드
bool check(int row, int col, int n) {
	int first = paper[row][col];

	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (first != paper[i][j])
				return false;
		}
	}

	return true;
}

void func(int row, int col, int n) {

	if (check(row, col, n)) {
		if (paper[row][col] == -1) {
			num1++;
		}
		if (paper[row][col] == 0) {
			num2++;
		}
		if (paper[row][col] == 1) {
			num3++;
		}
		return;
	}

	else {
		int size = n / 3;
		// 1
		func(row, col, size);
		// 2
		func(row + size, col, size);
		// 3
		func(row + size*2, col, size);
		// 4
		func(row, col + size, size);
		// 5
		func(row, col + size * 2, size);
		// 6
		func(row + size, col + size, size);
		// 7
		func(row + size*2, col + size, size);
		// 8
		func(row + size, col + size * 2, size);
		// 9
		func(row + size * 2, col + size * 2, size);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			paper[i][j] = num;
		}
	}

	func(0, 0, N);

	cout << num1 << "\n";
	cout << num2 << "\n";
	cout << num3 << "\n";

}
