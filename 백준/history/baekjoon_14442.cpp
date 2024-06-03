// 벽 부수고 이동하기 2/ baekjoon_14442.cpp
// https://www.acmicpc.net/problem/14442

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;
int map[1001][1001];
bool visited[1001][1001][11];

void Input() {

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int value;
            scanf("%1d", &value);
            map[i][j] = value;
        }
    }
    
}


int BFS() {

    queue<pair<pair<int, int>,pair<int,int>>> q;
    int moveX[4] = { 1, -1,0,0 };
    int moveY[4] = { 0, 0, 1, -1 };


    visited[1][1][1] = true;
    q.push({ { 1,1 },{1,0} });

    while (!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int wall = q.front().second.second;
        q.pop();

        if (x == N && y == M)
            return cnt;
  
        for (int i = 0; i < 4; i++) {

            int nowX = x + moveX[i];
            int nowY = y + moveY[i];

            if (nowX <= 0 || nowX > N || nowY <= 0 || nowY > M)
                continue;
            if (visited[nowX][nowY][wall])
                continue;

            if (map[nowX][nowY] == 0) {
                q.push({ { nowX,nowY },{cnt + 1, wall} });
                visited[nowX][nowY][wall] = true;
            }

            // visited[nowX][nowY][wall - 1] == false 조건 없을 시 시간초과 발생...
            else if (map[nowX][nowY] == 1 && wall < K && visited[nowX][nowY][wall - 1] == false) {
                
                visited[nowX][nowY][wall + 1] = true;
                q.push({ { nowX,nowY }, {cnt + 1, wall + 1} });
            }
        }
        
    }

    return -1;
}

void Solve() {

    printf("%d", BFS());

}

int main() {

    Input();
    Solve();
    
}
