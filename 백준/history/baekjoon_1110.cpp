// 더하기 사이클/ baekjoon_1110.cpp
// https://www.acmicpc.net/problem/1110

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int arr[2];
	arr[0] = n / 10;
	arr[1] = n % 10;
	int cnt = 0;
	while (true) {
		cnt++;
		int n1 = arr[0] + arr[1];
		int n2 = n1 % 10 + arr[1] * 10;
		if (n2 == n)
			break;
		arr[0] = n2 / 10;
		arr[1] = n2 % 10;
	
	}

	cout << cnt;

}
