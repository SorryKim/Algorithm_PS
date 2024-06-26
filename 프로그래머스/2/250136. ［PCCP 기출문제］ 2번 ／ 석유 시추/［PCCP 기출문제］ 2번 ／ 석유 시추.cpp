#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int moveX[4] = {0, 0, -1, 1};
int moveY[4] = {1, -1, 0, 0};
bool visited[501][501];
int maxOil[501] = {0};

int solution(vector<vector<int>> land) {
    int answer = 0;
    int N = land.size();
    int M = land[0].size();

    // 초기화
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            visited[y][x] = false;
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (land[y][x] == 1 && !visited[y][x]) {
                set<int> mySet;
                queue<pair<int, int>> q;
                q.push({y, x});
                visited[y][x] = true;

                int cnt = 0;

                while (!q.empty()) {
                    int nowY = q.front().first;
                    int nowX = q.front().second;
                    q.pop();

                    cnt++;
                    mySet.insert(nowX);

                    for (int i = 0; i < 4; i++) {
                        int nextY = nowY + moveY[i];
                        int nextX = nowX + moveX[i];

                        if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
                            if (land[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                                visited[nextY][nextX] = true;
                                q.push({nextY, nextX});
                            }
                        }
                    }
                }

                for (int x : mySet) {
                    maxOil[x] += cnt;
                }
            }
        }
    }

    answer = *max_element(maxOil, maxOil + M);
    return answer;
}