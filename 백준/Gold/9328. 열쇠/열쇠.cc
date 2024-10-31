#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int h, w;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};

int BFS(vector<vector<char>>& graph, vector<bool>& keys) {
    int result = 0;

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> q;
    vector<pair<int, int>> doors[26];

    // 가장자리에서 시작 가능한 위치를 큐에 추가
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                if (graph[i][j] == '.' || graph[i][j] == '$') {
                    visited[i][j] = true;
                    q.push({i, j});
                }
                else if (graph[i][j] >= 'a' && graph[i][j] <= 'z') {
                    // 열쇠 획득
                    int idx = graph[i][j] - 'a';
                    keys[idx] = true;
                    graph[i][j] = '.';
                    visited[i][j] = true;
                    q.push({i, j});
                }
                else if (graph[i][j] >= 'A' && graph[i][j] <= 'Z') {
                    int idx = graph[i][j] - 'A';
                    if (keys[idx]) {
                        visited[i][j] = true;
                        q.push({i, j});
                    }
                    else {
                        doors[idx].push_back({i, j});
                    }
                }
            }
        }
    }

    while (!q.empty()) {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();

        if (graph[nowx][nowy] == '$') {
            result++;
            graph[nowx][nowy] = '.'; // 중복 카운트를 방지하기 위해 빈 공간으로 변경
        }

        // 현재 위치에 열쇠가 있는 경우
        if (graph[nowx][nowy] >= 'a' && graph[nowx][nowy] <= 'z') {
            int idx = graph[nowx][nowy] - 'a';
            if (!keys[idx]) {
                keys[idx] = true;
                // 새로운 열쇠로 열 수 있는 문들을 큐에 추가
                for (auto pos : doors[idx]) {
                    if (!visited[pos.first][pos.second]) {
                        visited[pos.first][pos.second] = true;
                        q.push(pos);
                    }
                }
            }
            graph[nowx][nowy] = '.'; // 열쇠를 획득했으므로 빈 공간으로 변경
        }

        for (int i = 0; i < 4; i++) {
            int nextx = nowx + dirx[i];
            int nexty = nowy + diry[i];

            if (nextx >= 0 && nextx < h && nexty >= 0 && nexty < w) {

                if (visited[nextx][nexty] || graph[nextx][nexty] == '*')
                    continue;

                if (graph[nextx][nexty] == '.' || graph[nextx][nexty] == '$') {
                    visited[nextx][nexty] = true;
                    q.push({nextx, nexty});
                }
                else if (graph[nextx][nexty] >= 'a' && graph[nextx][nexty] <= 'z') {
                    visited[nextx][nexty] = true;
                    q.push({nextx, nexty});
                }
                else if (graph[nextx][nexty] >= 'A' && graph[nextx][nexty] <= 'Z') {
                    int idx = graph[nextx][nexty] - 'A';
                    if (keys[idx]) {
                        visited[nextx][nexty] = true;
                        q.push({nextx, nexty});
                    }
                    else 
                        doors[idx].push_back({nextx, nexty}); // 아직 열 수 없는 문이므로 위치 저장
                    
                }
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        cin >> h >> w;
        vector<vector<char>> graph(h, vector<char>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> graph[i][j];
            }
        }

        string skey;
        cin >> skey;
        vector<bool> keys('z' - 'a' + 1, false);

        if (skey != "0") {
            for (int i = 0; i < skey.size(); i++) {
                int idx = skey[i] - 'a';
                keys[idx] = true;
            }
        }

        int answer = BFS(graph, keys);

        cout << answer << '\n';
    }

    return 0;
}