// 불! / baekjoon_4179.cpp
// https://www.acmicpc.net/problem/4179

#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321;

int R, C;
char graph[1001][1001];
int fire[1001][1001];
bool visit[1001][1001];
queue<pair<int, int>> fireQ;
int jihoonX, jihoonY;
int moveX[4] = { 1 , -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };

void Input() {

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 'J') {
                jihoonX = i;
                jihoonY = j;
            }

            if (graph[i][j] == 'F') {
                fireQ.push({ i, j });
                fire[i][j] = 0;
            }
            else
                fire[i][j] = INF;
        }
    }

}

void MoveFire() {

    while (!fireQ.empty()) {
        
        int x0 = fireQ.front().first;
        int y0 = fireQ.front().second;
        fireQ.pop();

        for (int i = 0; i < 4; i++) {
            int nowX = x0 + moveX[i];
            int nowY = y0 + moveY[i];
            if (nowX < 0 || nowY < 0 || nowX >= R || nowY >= C)
                continue;

            
            if (graph[nowX][nowY] != '#') {

                // 불이 번진 시각 체크
                if (fire[nowX][nowY] > fire[x0][y0] + 1) {
                    fire[nowX][nowY] = fire[x0][y0] + 1;
                    fireQ.push({ nowX,nowY });
                }
            }
        }
        
    }
}

int MoveJihoon() {

    queue<pair<pair<int, int>, int>> q;
    q.push({ { jihoonX, jihoonY }, 0 });
    visit[jihoonX][jihoonY] = true;

    while (!q.empty()) {

        int x0 = q.front().first.first;
        int y0 = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            
            int nowX = x0 + moveX[i];
            int nowY = y0 + moveY[i];

            // 지훈이가 그래프를 벗어난 경우, 탈출
            if (nowX < 0 || nowY < 0 || nowX >= R || nowY >= C)
                return cnt + 1;

            if (graph[nowX][nowY] != '#' && !visit[nowX][nowY]) {
                
                // 지훈이가 먼저 온 경우에만 움직일 수 있음
                if (fire[nowX][nowY] > cnt + 1) {
                    visit[nowX][nowY] = true;
                    q.push({ { nowX,nowY }, cnt + 1 });
                }
            }
        }
    }
    
    return -1;
}

void Solve() {

    MoveFire();
    int result = MoveJihoon();

    result == -1 ? cout << "IMPOSSIBLE" << "\n" : cout << result << "\n";
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();
    Solve();

}
