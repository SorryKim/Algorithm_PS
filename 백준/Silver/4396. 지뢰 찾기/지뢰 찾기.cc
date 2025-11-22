#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> mine(n), open(n);

    for (int i = 0; i < n; i++) cin >> mine[i];
    for (int i = 0; i < n; i++) cin >> open[i];

    bool exploded = false;
    vector<string> ans(n, string(n, '.'));

    // 먼저 열린 안전 칸에 숫자 채우기 + 지뢰 밟았는지 체크
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (open[i][j] == 'x') {
                if (mine[i][j] == '*') {
                    exploded = true;
                } else {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                        if (mine[ni][nj] == '*') cnt++;
                    }
                    ans[i][j] = char('0' + cnt);
                }
            }
        }
    }

    // 지뢰 밟았으면 모든 지뢰 위치 공개
    if (exploded) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mine[i][j] == '*') ans[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    

    return 0;
}
