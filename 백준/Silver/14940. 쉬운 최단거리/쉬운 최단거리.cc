#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[1001][1001];
pair<int, int> start;
int moveX[4] = {1,-1,0,0};
int moveY[4] = {0,0,1,-1};

void Input() {
   

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                start.first = i;
                start.second = j;
                graph[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (graph[i][j] != 0)
                graph[i][j] = -1;
        }
    }

}

void Solve() {

    queue<pair<int, int>> q;
    q.push({ start.first, start.second });

    while (!q.empty()) {
        int x0 = q.front().first;
        int y0 = q.front().second;
        int val = graph[x0][y0];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nowX = x0 + moveX[i];
            int nowY = y0 + moveY[i];

            if (nowX >=0 && nowX < n && nowY >= 0 && nowY < m) {
                
                if (graph[nowX][nowY] == -1) {
                    graph[nowX][nowY] = val + 1;
                    q.push({ nowX, nowY });
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}


