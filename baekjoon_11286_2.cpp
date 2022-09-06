// 절댓값 힙(우선순위 큐 사용) / baekjoon_11286
// https://www.acmicpc.net/problem/11286

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq_plus; // 양수, 오름차순으로 정렬한 큐
	priority_queue<int> pq_minus; // 음수, 내림차순으로 정렬한 큐

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			if (pq_minus.empty() && pq_plus.empty()) {
				cout << "0\n";
			}
			else if (pq_minus.empty()) {
				cout << pq_plus.top() << "\n";
				pq_plus.pop();
			}
			else if(pq_plus.empty()){
				cout << pq_minus.top() << "\n";
				pq_minus.pop();
			}
			else {
				if (abs(pq_plus.top()) >= abs(pq_minus.top())) {
					cout << pq_minus.top() << "\n";
					pq_minus.pop();
				}
				else {
					cout << pq_plus.top() << "\n";
					pq_plus.pop();
				}
			}
		}
		else {
			if (n > 0) {
				pq_plus.push(n);
			}
			else {
				pq_minus.push(n);
			}
		}
	}
}
