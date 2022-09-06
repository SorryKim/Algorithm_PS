// baekjoon_1018
// https://www.acmicpc.net/problem/1018
#include <iostream>

using namespace std;

char white_arr[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

char black_arr[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

int check(char** mat, int x, int y) {
	int white = 0, black = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (mat[i][j] != black_arr[i-x][j-y])
				black++;
			else if (mat[i][j] != white_arr[i-x][j-y])
				white++;
			else
				continue;
		}
	}

	if (black < white)
		return black;
	else
		return white;
}

int main() {

	int m, n;
	cin >> n >> m;

	// 2차원 배열 동적할당
	char** matrix = new char*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new char[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			matrix[i][j] = ch;
		}
	}

	int min = 64;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int result = check(matrix, i, j);
			if (min > result)
				min = result;
		}
	}

	cout << min << endl;
	
}
