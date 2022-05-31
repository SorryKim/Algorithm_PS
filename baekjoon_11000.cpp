// 강의실 배정/ baekjoon_11000.cpp
// https://www.acmicpc.net/problem/11000

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 값 입력받기
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ start,end });
	}

	// 시작시간이 낮은차순으로 정렬
	sort(v.begin(), v.end());

	// 첫번째 끝나는 우선순위 큐에 push
	pq.push(v[0].second);

	// 같은회의실에서 할 수 있는 경우는 큐에서 pop 아닐 경우 push해서 회의실 갯수를 구함
	for (int i = 1; i < N; i++) {
		pq.push(v[i].second);
		if (pq.top() <= v[i].first)
			pq.pop();
	}

	cout << pq.size();
}
