// 벽 부수고 이동하기 4 / baekjoon_16946.cpp
// https://www.acmicpc.net/problem/16496

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int graph[1001][1001];
bool visit[1001][1001];

void Input() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
}

void Output() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", graph[i][j] % 10);
        }
        printf("\n");
    }
}

// visit false로 초기화
// 매 탐색마다 사용하면 시간초과 발생~!@~!@!
void Clear() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = false;
        }
    }

}

void BFS(int x, int y) {

    queue<pair<int, int>> q;
    vector<pair<int, int>> wall; // 탐색 도중 만나는 벽
    int cnt = 1;
    q.push({ x,y });
    visit[x][y] = true;

    int moveX[4] = { 1,-1,0,0 };
    int moveY[4] = { 0,0,1,-1 };

    while (!q.empty()) {

        int x0 = q.front().first;
        int y0 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nowX = x0 + moveX[i];
            int nowY = y0 + moveY[i];

            if (nowX < 0 || nowX >= N || nowY < 0 || nowY >= M)
                continue;

            if (!visit[nowX][nowY] && graph[nowX][nowY] == 0) {
                cnt++;
                visit[nowX][nowY] = true;
                q.push({ nowX,nowY });
            }

            else if (!visit[nowX][nowY] && graph[nowX][nowY] != 0) {
                visit[nowX][nowY] = true;
                wall.push_back({ nowX,nowY });
            }
        }

    }

    // 지금까지의 갈 수 있는길들을 다음 벽들에게 전달
    for (int i = 0; i < wall.size(); i++) {
        graph[wall[i].first][wall[i].second] += cnt;
        visit[wall[i].first][wall[i].second] = false;
    }
}

void Solve() {
   

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            // 0에서 탐색 시작하여 만나는 벽들에게 경로 전달
            if (graph[i][j] == 0 && !visit[i][j]) {
                BFS(i, j);
            }
        }
    }

}

int main() {

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    Input();
    Solve();
    Output();
}
