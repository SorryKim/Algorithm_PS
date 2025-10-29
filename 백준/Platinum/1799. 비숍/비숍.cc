#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[10][10];
bool diag1[20];  // x + y
bool diag2[20];  // x - y + (N - 1)
int ansBlack = 0, ansWhite = 0;

// DFS 함수
void dfs(int idx, int cnt, bool color) {
    
    // idx는 체스판을 1차원으로 순회하는 인덱스
    if (idx >= N * N) {
        if (color) ansBlack = max(ansBlack, cnt);
        else ansWhite = max(ansWhite, cnt);
        return;
    }

    int x = idx / N;
    int y = idx % N;

    // 다음 인덱스로 이동
    dfs(idx + 1, cnt, color);

    // 체스판 색이 현재 탐색 색과 다르면 스킵
    if ((x + y) % 2 != color) return;

    // 놓을 수 없는 칸이면 스킵
    if (board[x][y] == 0) return;

    // 대각선 충돌 체크
    if (!diag1[x + y] && !diag2[x - y + (N - 1)]) {
        diag1[x + y] = diag2[x - y + (N - 1)] = true;
        dfs(idx + 1, cnt + 1, color);
        diag1[x + y] = diag2[x - y + (N - 1)] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 검은 칸, 흰 칸 따로 탐색
    dfs(0, 0, 0); // 흰 칸
    dfs(0, 0, 1); // 검은 칸

    cout << ansBlack + ansWhite << "\n";
    return 0;
}
