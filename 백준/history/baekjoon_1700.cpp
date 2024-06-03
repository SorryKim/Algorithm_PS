// 멀티탭 스케줄링 / baekjoon_1700.cpp
// https://www.acmicpc.net/problem/1700

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, result;
vector<int> v;
int plug[101];

void Input() {

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}


}

void Solve() {

	result = 0;
	for (int i = 0; i < K; i++) {

		bool b = false;
		int now = v[i];

		// 이미 꽃혀있는 경우
		for (int j = 0; j < N; j++) {
			if (plug[j] == now) {
				b = true;
				break;
			}
		}
		if (b)
			continue;

		// 빈자리 있는 경우
		for (int j = 0; j < N; j++) {
			if (plug[j] == 0) {
				plug[j] = now;
				b = true;
				break;
			}
		}
		if (b)
			continue;

		int last = -1;
		int index = -1;

		for (int j = 0; j < N; j++) {
			int temp = 0;
			for (int k = i + 1; k < K; k++){
				if (v[k] == plug[j])
					break;
				temp++;
			}
			if (temp > last)
			{
				last = temp;
				index = j;
			}
		}

		plug[index] = v[i];
		result++;
	}

	cout << result << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
