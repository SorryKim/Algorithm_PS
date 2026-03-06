#include <iostream>
using namespace std;

int R, C, H;
char grid[101][101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> H;

    for (int z = 0; z < H; z++) {
        for (int r = 0; r < R; r++) {
            cin >> grid[z][r];
        }
    }

    int dz[3] = {-1, 0, 1};
    int dr[3] = {-1, 0, 1};
    int dc[3] = {-1, 0, 1};

    for (int z = 0; z < H; z++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {

                if (grid[z][r][c] == '*') {
                    cout << '*';
                    continue;
                }

                int cnt = 0;

                for (int i : dz) {
                    for (int j : dr) {
                        for (int k : dc) {
                            if (i == 0 && j == 0 && k == 0) continue;

                            int nz = z + i;
                            int nr = r + j;
                            int nc = c + k;

                            if (nz < 0 || nz >= H ||
                                nr < 0 || nr >= R ||
                                nc < 0 || nc >= C) continue;

                            if (grid[nz][nr][nc] == '*')
                                cnt++;
                        }
                    }
                }

                cout << (cnt % 10);
            }
            cout << '\n';
        }
    }

    return 0;
}