// 감소하는 수 / baekjoon_1038.cpp
// https://www.acmicpc.net/problem/1083

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int temp;
long long result[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// -1로 초기화
	for (int i = 0; i <= 1000000; i++)
		result[i] = -1;

	// 0 ~ 9는 감소하는 수
	for (int i = 0; i < 10; i++)
		result[i] = i;


	// 뒤에 작은숫자를 붙혀가며 배열에 저장
	temp = 10;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < result[i] % 10; j++) {
			result[temp] = result[i] * 10 + j;
			temp++;
		}
	}

	if (result[N] == -1)
		cout << -1;
	else
		cout << result[N];
}
