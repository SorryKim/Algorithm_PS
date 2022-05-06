// N번째 큰 수 / baekjoon_2075.cpp
// https://www.acmicpc.net/problem/2075

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	priority_queue<int,vector<int>,greater<int>> pq; // 오름차순 우선순위 큐

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			pq.push(num);
			if (pq.size() > N) 
				pq.pop();
		}
	}

	// 결국 큐에남는 수는 N번째 수 ~ 가장 큰 수
	// top에 수가 N번째로 큰 수이다.
	cout << pq.top();

}
