// baekjoon_2164
// https://www.acmicpc.net/problem/2164

#include<iostream>
#include<queue>
using namespace std;

int main() {
	int num;
	queue<int> q;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		if (q.size() == 1)
			break;
		else {
			int num = q.front();
			q.pop();
			q.push(num);
		}
	}

	int result = q.front();
	cout << result;
}
