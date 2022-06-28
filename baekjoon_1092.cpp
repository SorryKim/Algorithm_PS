// 배 / baekjoon_1092.cpp
// https://www.acmicpc.net/problem/1092

#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;

vector<int> crain,box;

bool compare(int a, int b) {
	return a > b;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int limit;
		cin >> limit;
		crain.push_back(limit);
	}
	sort(crain.begin(), crain.end(), compare);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int weight;
		cin >> weight;
		box.push_back(weight);
	}
	sort(box.begin(), box.end(), compare);
}


int greed() {
	if (box[0] > crain[0])
		return -1;

	int cnt = 0;
	while (true) {
		cnt++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < box.size(); j++) {

				// 담을 수 있는 경우
				if (crain[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}

		if (box.empty())
			break;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	sort(crain.begin(), crain.end(), compare);

	cout << greed();
}
