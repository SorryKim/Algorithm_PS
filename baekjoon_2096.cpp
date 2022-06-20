// 내려가기 / baekjoon_2096.cpp
// https://www.acmicpc.net/problem/2096

#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int maxDP[3] = { 0,0,0 };
	int minDP[3] = { 0,0,0 };

	// 음의 입력이 없으므로, 누적합으로 결과 도출 가능
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (i == 0) {
			maxDP[0] = a;
			maxDP[1] = b;
			maxDP[2] = c;
			minDP[0] = a;
			minDP[1] = b;
			minDP[2] = c;
		}
		else {
			// 최댓값
			int value0 = maxDP[0];
			int value1 = maxDP[1];
			int value2 = maxDP[2];
			maxDP[0] = max(maxDP[0] + a, maxDP[1] + a);
			maxDP[2] = max(maxDP[1] + c, maxDP[2] + c);
			maxDP[1] = max(max(value0, value1), value2) + b;

			// 최솟값
			value0 = minDP[0];
			value1 = minDP[1];
			value2 = minDP[2];
			minDP[0] = min(minDP[0] + a, minDP[1] + a);
			minDP[2] = min(minDP[1] + c, minDP[2] + c);
			minDP[1] = min(min(value0, value1), value2) + b;
			
		}
	}

	cout << max(maxDP[0], max(maxDP[1], maxDP[2])) << " " << min(minDP[0], min(minDP[1], minDP[2]));


}
