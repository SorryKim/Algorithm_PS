// 카드 합체 놀이 / baekjoon_15903.cpp
// https://www.acmicpc.net/problem/15903

#include <iostream>
#include <queue>
using namespace std;

class Card {
public:
	long long num;
	Card() {}
	Card(long long n) {
		num = n;
	}

	bool operator<(const Card& b) const {
		if (num == b.num)
			return false;
		return num > b.num;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<Card> q;
	int n, m;
	cin >> n >> m;

	while (n--) {
		int num;
		cin >> num;
		Card card = { num };
		q.push(card);
	}
	
	while (m--) {
		Card card1 = q.top();
		q.pop();
		Card card2 = q.top();
		q.pop();

		long long temp = card1.num;
		card1.num += card2.num;
		card2.num += temp;

		q.push(card1);
		q.push(card2);
	}

	long long sum = 0;
	while (!q.empty()) {
		sum += q.top().num;
		q.pop();
	}

	cout << sum << "\n";

	
}
