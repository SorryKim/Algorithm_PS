#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R, C;
vector<string> yard;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// BFS 탐색
pair<int, int> bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int sheep = 0, wolf = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 양이나 늑대 개수
        if (yard[cx][cy] == 'o') sheep++;
        else if (yard[cx][cy] == 'v') wolf++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && yard[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return {sheep, wolf};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    yard.resize(R);
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)cin >> yard[i];
    

    int totalSheep = 0, totalWolf = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && yard[i][j] != '#') {
                auto [sheep, wolf] = bfs(i, j);
                if (sheep > wolf) totalSheep += sheep;
                else totalWolf += wolf;
            }
        }
    }

    cout << totalSheep << " " << totalWolf << "\n";
    return 0;
}
