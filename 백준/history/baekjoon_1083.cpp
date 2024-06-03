// 소트 / baekjoon_1083.cpp
// https://www.acmicpc.net/problem/1083

#include <iostream>
using namespace std;

int N, S;
int arr[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> S;

	for (int i = 0; i < N; i++) {

		// 초기값 설정
		int max = arr[i];
		int max_index = i;
		if (S == 0)
			break;

		// 확인할 범위 index
		int index = min(N, i + 1 + S);
		for (int j = i + 1; j < index; j++) {
			// 최댓값 설정
			if (max < arr[j]) {
				max = arr[j];
				max_index = j;
			}
		}

		// s감소, 움직인만큼 S감소
		S = S - (max_index - i);

		// swap
		for (int j = max_index; j > i; j--) {
			arr[j] = arr[j - 1];
		}
		arr[i] = max;
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}
