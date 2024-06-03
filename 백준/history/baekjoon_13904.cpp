// 과제 / baekjoon_13904.cpp
// https://www.acmicpc.net/problem/13904

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, result;
pair<int, int> arr[1000];
bool check[1000] = { false, };

void Input() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		arr[i] = { d,w };
	}

}

bool compare(pair<int, int> n1, pair<int, int> n2) {
	
	return n1.first > n2.first;
}

void Solve() {
	
	sort(arr, arr + N, compare);
	result = 0;

	for (int day = arr[0].first; day > 0; day--) {

		int maxV = 0;
		int index = -1;
		for (int i = 0; i < N; i++) {

			int time = arr[i].first;
			int score = arr[i].second;

			if (time < day)
				break;
			
			if (score > maxV && !check[i]) {
				index = i;
				maxV = score;
			}
		}
		if(index != -1)
			check[index] = true;
		result += maxV;
	}
	cout << result << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

}
