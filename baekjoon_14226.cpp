// 이모티콘 / baekjoon_14226.cpp
// https://www.acmicpc.net/problem/14226

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
int S;
int visit[1001][1001];

void Input() {

    cin >> S;
}

void Solve() {

    int result = INF;

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++)
            visit[i][j] = -1;
    }

    visit[1][0] = 0;
    queue<pair<int, int>> q;
    q.push({ 1,0 });

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        int time = visit[x][y];
        q.pop();

        // 이모티콘이 S개가 되는 경우
        if (x == S) {
            result = min(result, time);
            continue;
        }

        // 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        if (visit[x][x] == -1) {
            visit[x][x] = time + 1;
            q.push({ x,x });
        }

        // 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        if (x + y <= S && visit[x + y][y] == -1) {
            visit[x + y][y] = time + 1;
            q.push({ x + y , y });
        }

        // 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
        if (x - 1 >= 0 && visit[x - 1][y] == -1) {
            visit[x - 1][y] = time + 1;
            q.push({ x - 1, y });
        }
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

}
