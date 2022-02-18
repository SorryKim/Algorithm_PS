// baekjoon_2579
// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <algorithm>
using namespace std;

int stairs[301] = { 0 };
int sum[301] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int value;
		cin >> value;
		stairs[i] = value;
	}

	sum[0] = stairs[0];
	sum[1] = max(stairs[1], stairs[0] + stairs[1]);
	sum[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < num; i++) {
		// 3연속으로 한 칸씩 뛸 수 없음을 고려
		sum[i] = max(sum[i - 2] + stairs[i], stairs[i] + stairs[i - 1] + sum[i - 3]);
	}

	cout << sum[num - 1];

}
