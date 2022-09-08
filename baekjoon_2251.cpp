// 물통 / baekjoon_2251.cpp
// https://www.acmicpc.net/problem/2251

#include <iostream>
#include <queue>
using namespace std;

int A, B, C;
bool check[201][201][201] = {false,};
bool result[201] = { false, };

void input() {

	cin >> A >> B >> C;

}

void BFS() {

	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0,0 }, C });
	
	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		
		q.pop();

		if (check[a][b][c])
			continue;

		check[a][b][c] = true;

		if(a == 0)
			result[c] = true;

		// A -> B
		if (a + b > B)
			q.push({ {a + b - B, B}, c });
		else
			q.push({ { 0, a + b }, c });

		// A -> C
		if (a + c > C)
			q.push({ { a + b - C,b }, C });
		else
			q.push({ { 0, b }, a + c });

		// B -> A
		if (b + a > A)
			q.push({ {A, a + b - A}, c });
		else
			q.push({ {a + b, 0}, c });

		// B -> C
		if (b + c > C)
			q.push({ {a,b + c - C},C });
		else
			q.push({ {a,0},b + c });

		
		// C -> A
		if (a + c > A)
			q.push({ {A,b}, a + c - A });
		else
			q.push({ {a + c,b},0 });
		
		// C -> B
		if (b + c > B)
			q.push({ {a,B},b + c - B });
		else
			q.push({ {a,b + c},0 });

	}

}

void solve() {
	
	BFS();

	for(int i = 0; i <= C; i++) {
		if (result[i])
			cout << i << " ";
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	
}