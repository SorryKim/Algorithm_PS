// baekjoon_11057
// https://www.acmicpc.net/problem/11057
#include <iostream>
using namespace std;

int arr[1001][10] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		arr[0][i] = 0;
		arr[1][i] = 1;
	}

	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9) {
				arr[i][j] = arr[i - 1][9];
			}
			if (j == 8){
				arr[i][j] = arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 7) {
				arr[i][j] = arr[i-1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 6) {
				arr[i][j] = arr[i - 1][6] + arr[i - 1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 5) {
				arr[i][j] = arr[i - 1][5] + arr[i - 1][6] + arr[i - 1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 4) {
				arr[i][j] = arr[i - 1][4] + arr[i - 1][5] + arr[i - 1][6] + arr[i - 1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 3) {
				arr[i][j] = arr[i - 1][3] + arr[i - 1][4] + arr[i - 1][5] + arr[i - 1][6] + arr[i - 1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 2) {
				arr[i][j] = arr[i - 1][2] + arr[i - 1][3] + arr[i - 1][4] + arr[i - 1][5] + arr[i - 1][6] + arr[i - 1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 1) {
				arr[i][j] = arr[i - 1][1] + arr[i - 1][2] + arr[i - 1][3] + arr[i - 1][4] + arr[i - 1][5] + arr[i - 1][6] + arr[i - 1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			if (j == 0) {
				arr[i][j] = arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2] + arr[i - 1][3] + arr[i - 1][4] + arr[i - 1][5] + arr[i - 1][6] + arr[i - 1][7] + arr[i - 1][8] + arr[i - 1][9];
			}
			arr[i][j] = arr[i][j] % 10007;
		}
	}
	
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + arr[N][i]) % 10007;
	}

	cout << sum;
}
