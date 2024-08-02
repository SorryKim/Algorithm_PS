#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

char graph[25];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };
int answer = 0;

// 해당 조합이 칠공주파를 결성가능한지 확인
bool Check(vector<int>& v) {

    bool map[5][5];
    bool visit[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = false;
            visit[i][j] = false;
        }
    }

    int cntS = 0;
    int cntY = 0;

    // 2차원 좌표로 변경 및 수 확인
    for (int i = 0; i < v.size(); i++) {
        int x = v[i] / 5;
        int y = v[i] % 5;
        map[x][y] = true;
        if (graph[v[i]] == 'S')
            cntS++;
        else
            cntY++;
    }

    // 임도연파가 더 많은 경우 불가능
    if (cntY >= 4)
        return false;


    queue<pair<int, int>> q;
    int cnt = 0;
    q.push({ v[0] / 5, v[0] % 5 });
    visit[v[0] / 5][v[0] % 5] = true;

    while (!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        cnt++;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];

            if (nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5) {
                if (map[nextX][nextY] && !visit[nextX][nextY]) {
                    visit[nextX][nextY] = true;
                    q.push({ nextX, nextY });
                }
            }

        }
    }

    return cnt == 7 ? true : false;
}

// 25개에서 7개 뽑기
void DFS(int start, vector<int>& v) {
    
    if (v.size() == 7) {
        if (Check(v))
            answer++;
        return;
    }

    for (int i = start; i < 25; i++) {
        v.push_back(i);
        DFS(i + 1, v);
        v.pop_back();
    }
}





int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            graph[i*5 + j] = s[j];
        }
    }

    vector<int> v;
    DFS(0, v);


    cout << answer << "\n";
    return 0;
}
