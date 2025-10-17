#include <iostream>
#include <vector>
using namespace std;

int N, M, R;
int arr[301][301];

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
}

void rotate() {
    int layers = min(N, M) / 2;

    for (int depth = 1; depth <= layers; depth++) {
        vector<pair<int, int>> pos;
        vector<int> vals;

        int top = depth;
        int left = depth;
        int bottom = N - depth + 1;
        int right = M - depth + 1;

        // 반시계 방향 순서로 좌표 수집
        // 위쪽 (왼 → 오)
        for (int j = left; j < right; j++) pos.push_back({top, j});
        // 오른쪽 (위 → 아래)
        for (int i = top; i < bottom; i++) pos.push_back({i, right});
        // 아래쪽 (오 → 왼)
        for (int j = right; j > left; j--) pos.push_back({bottom, j});
        // 왼쪽 (아래 → 위)
        for (int i = bottom; i > top; i--) pos.push_back({i, left});

        // 값 수집
        for (auto a : pos) vals.push_back(arr[a.first][a.second]);
    
        int len = vals.size();
        int cntR = R % len;

        vector<int> result(len);
        // 반시계 방향 회전
        for (int i = 0; i < len; i++)
            result[i] = vals[(i + cntR) % len];

        // 다시 채우기
        for (int i = 0; i < len; i++) {
            auto a = pos[i];
            arr[a.first][a.second] = result[i];
        }
    }
}

int main() {
    input();
    rotate();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
