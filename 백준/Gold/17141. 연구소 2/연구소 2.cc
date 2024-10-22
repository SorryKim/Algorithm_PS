#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int answer = 1e9;
vector<vector<int>> graph;
vector<pair<int, int>> place; // 바이러스를 놓을 수 있는 위치들
vector<vector<pair<int, int>>> start; // 바이러스 놓는 조합
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void Input() {
    cin >> N >> M;
    graph = vector<vector<int>>(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];

            // 벽인 경우
            if (graph[i][j] == 1)
                graph[i][j] = -1;

            // 바이러스를 넣을 수 있는 경우
            if (graph[i][j] == 2)
                place.push_back({i, j});
        }
    }
}

void DFS(int idx, vector<pair<int, int>> temp) {
    if (temp.size() == M) {
        start.push_back(temp);
        return;
    }

    for (int i = idx; i < place.size(); i++) {
        temp.push_back(place[i]);
        DFS(i + 1, temp);
        temp.pop_back();
    }
}

bool Finish(const vector<vector<bool>>& visited) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] != -1 && !visited[i][j])
                return false;
        }
    }
    
    return true;
}

void BFS(vector<pair<int, int>> virus) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, pair<int, int>>> q;

    for (auto a : virus) {
        visited[a.first][a.second] = true;
        q.push({0, {a.first, a.second}});
    }

    int time = 0;
    while (!q.empty()) {
        int level = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        time = max(time, level);

        for (int i = 0; i < 4; i++) {
            int next_x = x + dir_x[i];
            int next_y = y + dir_y[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
                if (visited[next_x][next_y] || graph[next_x][next_y] == -1)
                    continue;

                visited[next_x][next_y] = true;
                q.push({level + 1, {next_x, next_y}});
            }
        }
    }

    if (Finish(visited))
        answer = min(answer, time);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();

    // 바이러스를 놓을 수 있는 조합 완탐
    DFS(0, vector<pair<int, int>>());

    // 해당 조합마다 BFS를 이용해 전부 퍼지는 시점 조사
    for (auto now : start)
        BFS(now);

    if (answer == 1e9)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}
