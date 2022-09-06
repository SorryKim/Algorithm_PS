// baekjoon no.4948
// https://www.acmicpc.net/problem/4948

#include <iostream>
#include <cmath>
using namespace std;

// 0 ~ n까지 소수를 구하는 함수
int cal(int n) {
	int* array = new int[n+1];
	fill_n(array, n+1, true);
	array[0] = false;
	array[1] = false;
	// 에라토스테네스의 체를 이용해 소수가 아닐경우 false
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (array[i] == true) {
			for (int j = i * 2; j <= n; j += i) {
				array[j] = false;
			}
		}
	}

	// 소수개수 세기
	int count = 0;
	for (int i = 0; i < n+1 ; i++) {
		if (array[i] == true)
			count++;
	}

	return count;
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			exit(0);
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}

		int count_n = cal(n); // 0~n 소수개수
		int count_2n = cal(2 * n); // 0 ~ 2n 소수개수
		int result = count_2n - count_n; // n+1 ~ 2n 까지의 개수
		cout << result << "\n";
	}
}
