// baekjoon_2225
// https://www.acmicpc.net/problem/2225
#include <iostream>

using namespace std;

long long arr[201][201] = { 0, };

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		arr[1][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
			arr[i][j] = arr[i][j] % 1000000000;
		}
	}

	cout << arr[K][N];

}
