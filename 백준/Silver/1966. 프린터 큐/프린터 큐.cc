// baekjoon_1966
// https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> q; // (인덱스, 값)
		priority_queue<int> pq; // 내림차순으로 정렬된 큐

		// 큐에 정보 저장
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			q.push({ i,num });
			pq.push(num);
		}

		int count = 0;

		while (!q.empty()) {

			int index = q.front().first;
			int value = q.front().second;
			q.pop();

			
			if (pq.top() == value) {
				pq.pop();
				count++;
				if (index == m) { // 알고싶은 값의 위치
					cout << count << endl;
					break;
				}
			}
			else {
				q.push({ index,value });
			}
		}

	}
}