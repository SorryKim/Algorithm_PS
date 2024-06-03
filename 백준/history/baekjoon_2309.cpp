// 일곱 난쟁이 / baekjoon_2309.cpp
// https://www.acmicpc.net/problem/2309

#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

int sum() {
	int n = 0;
	for (int i = 0; i < 9; i++) {
		n += arr[i];
	}
	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	bool b = false;
	for (int i = 0; i < 9; i++) {
		int temp1 = arr[i];
		arr[i] = 0;
		for (int j = 0; j < 9; j++) {
			if (arr[j] == 0)
				continue;
			int temp2 = arr[j];
			arr[j] = 0;
			int result = sum();
			if (result == 100) {
				b = true;
				break;
			}
			arr[j] = temp2;
		}
		if (b)
			break;
		arr[i] = temp1;
	}
	
	sort(arr, arr + 9);

	for (int i = 2; i < 9; i++) {
		cout << arr[i] << "\n";
	}
	
}
