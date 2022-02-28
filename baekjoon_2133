// baekjoon_2133
// https://www.acmicpc.net/problem/2133

#include <iostream>
using namespace std;

int arr[31] = { 0, };

int main() {
	int N;
	cin >> N;

	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 3;
	arr[3] = 0;
	arr[4] = 11;

	for (int i = 6; i <= 30; i += 2) {
		arr[i] = arr[2] * arr[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) {
			arr[i] = arr[i] + (2 * arr[j]);
		}
		
	}
	cout << arr[N];
}
