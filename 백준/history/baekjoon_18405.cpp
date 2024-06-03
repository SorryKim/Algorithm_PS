// 경쟁적 전염  / baekjoon_18405.cpp
// https://www.acmicpc.net/problem/18405

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, S, X, Y;
int graph[201][201];
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

struct Virus {
	int num;
	int x;
	int y;

	Virus(int num, int x, int y) {
		this->num = num;
		this->x = x;
		this->y = y;
	}
	
};

vector<Virus> virus;
bool compare(const Virus& v1, const Virus& v2) {
	return v1.num < v2.num;
}


void Input() {
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			graph[i][j] = num;
			if (num >= 1 && num <= K) {
				virus.push_back(Virus(num, i, j));
			}
		}
	}

	cin >> S >> X >> Y;
}


void Solve() {

	int temp = 0;

	while (temp < S) {

		sort(virus.begin(), virus.end(), compare);
		int size = virus.size();

		for (int i = 0; i < size; i++) {

			Virus now = virus[i];
			for (int j = 0; j < 4; j++) {

				int x = now.x + moveX[j];
				int y = now.y + moveY[j];

				if (x <= 0 || x > N || y <= 0 || y > N || graph[x][y] > 0)
					continue;

				graph[x][y] = now.num;
				virus.push_back(Virus(graph[x][y], x, y));

			}
		}

		if (graph[X][Y] > 0)
			break;
		temp++;
	}


	cout << graph[X][Y] << "\n";
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
