// 숫자 카드 / baekjoon_10815.cpp
// https://www.acmicpc.net/problem/10815

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

vector<int> card;
vector<int> v;

void input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		card.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
}

void solve() {

	sort(card.begin(), card.end());
	for (auto a : v) {

		bool b = false;
		int left = 0;
		int right = N - 1;

		while (left <= right) {

			int mid = (left + right) / 2;

			if (card[mid] == a) {
				b = true;
				break;
			}

			if (card[mid] > a) 
				right = mid - 1;
			else
				left = mid + 1;
		}

		if (b)
			cout << "1 ";
		else
			cout << "0 ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}
