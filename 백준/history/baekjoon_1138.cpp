// 한 줄로 서기 / baekjoon_1138.cpp
// https://www.acmicpc.net/problem/1138

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	int arr[11];
	for (int i = 1; i <= 10; i++)
		arr[i] = -1;
	
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		// 키가 1인 경우
		if (i == 1) 
			arr[num + 1] = 1;

		else {
			// 키를 체크
			int cnt = 0;
			for (int j = 1; j <= N; j++) {
				if (arr[j] == -1)
					cnt++;
				if (cnt == num + 1 && arr[j] == -1) {
					arr[j] = i;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
}
