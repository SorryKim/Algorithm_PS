// 컵라면/ baekjoon_1781.cpp
// https://www.acmicpc.net/problem/1781

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> v;

void Input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

}


void Solve() {

	sort(v.begin(), v.end());
	long long sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {

		if (pq.size() < v[i].first) 
			pq.push(v[i].second);
		else {
			if (pq.top() < v[i].second) {
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
