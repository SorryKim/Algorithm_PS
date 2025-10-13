#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 상태: (x, y, 이동거리, 벽부순횟수, 낮/밤)
struct State {
    int x, y, dist, cnt, day;
};

int N, M, K;
vector<vector<int>> map;
bool visited[1000][1000][11][2]; // [x][y][벽부순횟수][낮/밤]

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    map.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }
}

int bfs() {
    queue<State> q;
    q.push({0, 0, 1, 0, 0}); // 시작점 (낮)
    visited[0][0][0][0] = true;

    while (!q.empty()) {
        auto [x, y, dist, cnt, day] = q.front();
        q.pop();

        // 도착 시 종료
        if (x == N - 1 && y == M - 1) return dist;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            // 이동할 칸이 벽이 아닐 때
            if (map[nx][ny] == 0) {
                if (!visited[nx][ny][cnt][1 - day]) {
                    visited[nx][ny][cnt][1 - day] = true;
                    q.push({nx, ny, dist + 1, cnt, 1 - day});
                }
            }
            // 벽일 때
            else {
                // 낮이면 벽 부수기 가능
                if (day == 0 && cnt < K && !visited[nx][ny][cnt + 1][1 - day]) {
                    visited[nx][ny][cnt + 1][1 - day] = true;
                    q.push({nx, ny, dist + 1, cnt + 1, 1 - day});
                }
                // 밤이면 대기해야 함
                else if (day == 1 && cnt < K) {
                    // 제자리에서 하루 기다리기
                    if (!visited[x][y][cnt][1 - day]) {
                        visited[x][y][cnt][1 - day] = true;
                        q.push({x, y, dist + 1, cnt, 1 - day});
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    input();
    cout << bfs() << "\n";
    return 0;
}
