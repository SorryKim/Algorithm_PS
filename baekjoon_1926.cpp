// 그림 / baekjoon_1926.cpp
// https://www.acmicpc.net/problem/1926

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[501][501];
bool visit[501][501];
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0, 0, 1,-1 };

void Input() {
    
    cin >> n >> m;
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            visit[i][j] = false;
        }
    }

}

int BFS(int x, int y) {

    visit[x][y] = true;
    int sum = 1;
    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty()) {
        
        int x0 = q.front().first;
        int y0 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nowX = x0 + moveX[i];
            int nowY = y0 + moveY[i];

            if (nowX < 0 || nowX >= n || nowY < 0 || nowY >= m)
                continue;
            if (graph[nowX][nowY] == 0 || visit[nowX][nowY])
                continue;
            sum++;
            visit[nowX][nowY] = true;
            q.push({ nowX,nowY });
        }
    }

    return sum;
}
void Solve() {

    int result = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visit[i][j]) {
                result = max(result, BFS(i, j));
                cnt++;
            }
        }
    }

    cout << cnt << "\n" << result << "\n";

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();

}
