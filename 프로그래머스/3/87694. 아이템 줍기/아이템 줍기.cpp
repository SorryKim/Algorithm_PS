#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};
bool visited[102][102] = {false, };
int graph[102][102] = {0, };

int BFS(int startX, int startY, int itemX, int itemY) {
    queue<pair<pair<int,int>, int>> q;
    q.push({{startX, startY}, 0});
    visited[startX][startY] = true; 

    while (!q.empty()) {
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (nowX == itemX && nowY == itemY) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];

            if (nextX >= 0 && nextX <= 101 && nextY >= 0 && nextY <= 101) {
                if (!visited[nextX][nextY] && graph[nextX][nextY] == 1) {
                    q.push({{nextX, nextY}, cnt + 1});
                    visited[nextX][nextY] = true; 
                }
            }
        }
    }

    return -1; 
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 그래프와 방문 배열 초기화
    for (int i = 0; i < 102; ++i) {
        for (int j = 0; j < 102; ++j) {
            graph[i][j] = 0;
            visited[i][j] = false;
        }
    }

    // 좌표 2배 확대 및 정규화
    for (auto a : rectangle) {
        int startX = a[0] * 2;
        int endX = a[2] * 2;
        int startY = a[1] * 2;
        int endY = a[3] * 2;

        // x축 테두리
        for (int i = startX; i <= endX; ++i) {
            if (graph[i][startY] == 0)
                graph[i][startY] = 1;
            if (graph[i][endY] == 0)
                graph[i][endY] = 1;
        }

        // y축 테두리
        for (int i = startY; i <= endY; ++i) {
            if (graph[startX][i] == 0)
                graph[startX][i] = 1;
            if (graph[endX][i] == 0)
                graph[endX][i] = 1;
        }

        // 내부 채우기
        for (int i = startX + 1; i < endX; ++i) {
            for (int j = startY + 1; j < endY; ++j) {
                graph[i][j] = 2;
            }
        }
    }

    // 캐릭터와 아이템 좌표 2배 확대
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    int answer = BFS(characterX, characterY, itemX, itemY) / 2;

    return answer;
}
