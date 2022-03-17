// baekjoon_1389
// https://www.acmicpc.net/problem/1389

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int people[101][101] = { 0, }; // 친구관계를 나타내는 그래프
int visited[101] = { 0, };     // 방문여부와 케빈 베이컨 수를 저장할 배열

// 해당인물의 케빈 베이컨 수를 반환하는 메소드
int BFS(int a) {
	queue<int> q;
	visited[a] = 1;
	q.push(a);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (people[now][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = visited[now] + 1;
			}
		}
	}

	// 해당인물의 케빈 베이컨 수를 반환
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += visited[i];
	}
	return sum - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	// 친구관계 입력
	while (M--) {
		int a, b;
		cin >> a >> b;
		people[a][b] = 1;
		people[b][a] = 1;
	}
	
	// 모든 인물의 케빈 베이컨 수를 비교
	int num = 10000000;
	int index = 0;
	for (int i = 1; i <= N; i++) {
		fill_n(visited, 101, 0);
		if (num > BFS(i)) {
			num = BFS(i);
			index = i;
		}
	}

	// 결과 출력
	cout << index;

}
