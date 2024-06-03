// baekjoon_10844
// https://www.acmicpc.net/problem/10844

#include <iostream>
using namespace std;

// arr[2][1] ==> 길이가 2이고 끝 숫자가 1인 경우의 숫자 수
int arr[101][10] = {0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		arr[0][i] = 0;
	}
	arr[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		arr[1][i] = 1;
	}

	// 끝이 0과 9 인경우는 앞에 1과 8밖에 못오기 때문에 구분해서 저장
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				arr[i][0] = arr[i - 1][j + 1];
			}
			else if (j == 9) {
				arr[i][9] = arr[i - 1][j - 1];
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			}
			arr[i][j] = arr[i][j] % 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + arr[N][i])% 1000000000;
	}

	cout << sum;

}
