// 요세푸스 문제 / baekjoon_1158.cpp
// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> result, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < K; j++) {
			int num = q.front();
			q.pop();
			q.push(num);
		}
		result.push(q.front());
		q.pop();
	}

	cout << "<";
	while (result.size() != 1) {
		cout << result.front() << ", ";
		result.pop();
	}
	cout << result.front() << ">";
	
}
