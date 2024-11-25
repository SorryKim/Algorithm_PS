#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, M;
pair<int, int> dir[5] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // 상, 하, 우, 좌

struct Shark {
    int x, y;       // 상어 위치
    int speed;      // 속력
    int direction;  // 이동 방향
    int size;       // 크기

    Shark(int a, int b, int c, int d, int e) : x(a), y(b), speed(c), direction(d), size(e) {}

    bool operator==(const Shark& other) const {
        return x == other.x && y == other.y && size == other.size;
    }
};

vector<Shark> sharks;

void Input() {
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks.emplace_back(r, c, s, d, z);
    }
}

void MoveSharks() {
    vector<vector<Shark>> board(R + 1, vector<Shark>(C + 1, Shark(0, 0, 0, 0, 0))); // 상어 정보 저장

    for (auto& shark : sharks) {
        int x = shark.x;
        int y = shark.y;
        int speed = shark.speed;
        int direction = shark.direction;

        // 상, 하 움직임
        if (direction <= 2) {
            speed %= (R - 1) * 2;
            for (int i = 0; i < speed; i++) {
                if (x == 1 && direction == 1) direction = 2;
                if (x == R && direction == 2) direction = 1;
                x += dir[direction].first;
            }
        }
        // 좌, 우 움직임
        else {
            speed %= (C - 1) * 2;
            for (int i = 0; i < speed; i++) {
                if (y == 1 && direction == 4) direction = 3;
                if (y == C && direction == 3) direction = 4;
                y += dir[direction].second;
            }
        }

        shark.x = x;
        shark.y = y;
        shark.direction = direction;

        // 같은 공간에 상어가 있는 경우, 크기 비교
        if (board[x][y].size == 0 || board[x][y].size < shark.size) {
            board[x][y] = shark; // 더 큰 상어로 갱신
        }
    }

    // board를 바탕으로 sharks 갱신
    sharks.clear();
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].size > 0) {
                sharks.push_back(board[i][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    int answer = 0;

    // 1. 낚시왕 이동
    for (int now = 1; now <= C; now++) {
        // 2. 낚시왕이 있는 열에서 가장 가까운 상어 잡기
        int targetIndex = -1, minRow = R + 1;
        for (int i = 0; i < sharks.size(); i++) {
            if (sharks[i].y == now && sharks[i].x < minRow) {
                minRow = sharks[i].x;
                targetIndex = i;
            }
        }

        // 상어를 잡으면 크기 추가 및 제거
        if (targetIndex != -1) {
            answer += sharks[targetIndex].size;
            sharks.erase(sharks.begin() + targetIndex);
        }

        // 3. 상어 이동
        MoveSharks();
    }

    cout << answer << "\n";
    return 0;
}
