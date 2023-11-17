#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int moveX[] = {-1,1,0,0};
int moveY[] = {0,0,-1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        int graph[101][101];
        int dist[101][101];
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                graph[i][j] = s[j] - '0';
                dist[i][j] = INT_MAX;
            }
        }

        queue<pair<int, int>> q;
        dist[0][0] = 0;
        q.push({ 0,0 });

        while (!q.empty()) {
            int nowX = q.front().first;
            int nowY = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextX = nowX + moveX[i];
                int nextY = nowY + moveY[i];

                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
                    continue;

                int val = dist[nowX][nowY] + graph[nextX][nextY];

                if (val < dist[nextX][nextY]) {
                    dist[nextX][nextY] = val;
                    q.push({ nextX,nextY });
                }

            }
        }
        cout << "#" << test << " " << dist[N -1][N - 1] << "\n";
    }

    return 0;
}
