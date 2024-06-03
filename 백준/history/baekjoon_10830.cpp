// 행렬 제곱  / baekjoon_10830.cpp
// https://www.acmicpc.net/problem/10830

#include<iostream>
using namespace std;

int N;
long long B;
int arr[5][5], result[5][5], temp[5][5];

void input() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
		result[i][i] = 1;
	}
}

void print() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

}

void calc(int A[5][5], int B[5][5], int C[5][5]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < N; k++) {
				temp[i][j] += (A[i][k] * B[k][j]);
			}
			temp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = temp[i][j];
		}
	}

}

void solve() {

	// 그냥 제곱할 시 시간초과
	/*while (B--)
	{
		calc(arr, result , result);

	}*/

	while (B > 0) {

		if ((B % 2) == 1) {
			calc(arr, result, result);
		}

		// 제곱을 제곱하여 log단위로 실행을 줄임
		calc(arr, arr, arr);
		B /= 2;
	}

	print();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}
