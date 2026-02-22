#include <iostream>

using namespace std;

int board[20][20];
int dx[4] = {0, 1, -1, 1}; // 가로, 세로, 대각 위, 대각 아래
int dy[4] = {1, 0, 1, 1};

int winner = 0;
int ansX = 0;
int ansY = 0;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            cin >> board[i][j];
        }
    }
}

bool check(int x, int y, int dir) {
    
    int stone = board[x][y];

    // 이전 칸 체크
    int prevX = x - dx[dir];
    int prevY = y - dy[dir];
    if (prevX >= 1 && prevX <= 19 && prevY >= 1 && prevY <= 19) {
        if (board[prevX][prevY] == stone)
            return false;
    }

    // 정확히 5개 세기
    int cnt = 0;
    int nx = x;
    int ny = y;

    while (nx >= 1 && nx <= 19 && ny >= 1 && ny <= 19
           && board[nx][ny] == stone) {
        cnt++;
        nx += dx[dir];
        ny += dy[dir];
    }

    return cnt == 5 ? true : false;
}

void solve() {

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                for (int d = 0; d < 4; d++) {
                    if (check(i, j, d)) {
                        winner = board[i][j];
                        ansX = i;
                        ansY = j;
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    input();
    solve();

    if (winner == 0) cout << 0 << "\n";
    else {
        cout << winner << "\n";
        cout << ansX << " " << ansY << "\n";
    }

    return 0;
}