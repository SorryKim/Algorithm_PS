// baekjoon_1931
// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second < p2.second)
		return true;
	else if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else
		return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int begin, end;
		cin >> begin >> end;
		v.push_back(make_pair(begin, end));
	}
	sort(v.begin(), v.end(), compare);

	int result = 0;
	int time = 0;
	for (auto a : v) {
		if (time <= a.first) {
			result++;
			time = a.second;
		}
	}

	cout << result;

}
