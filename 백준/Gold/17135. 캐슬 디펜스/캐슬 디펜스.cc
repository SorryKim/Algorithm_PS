#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int N, M, D;
vector<vector<int>> board;

struct Target {
    int dist, x, y;

    // priority_queue는 기본이 max-heap이므로 반대비교를 해야 함
    bool operator<(const Target& other) const {
        if (dist == other.dist) return y > other.y; // 열이 작을수록 우선
        return dist > other.dist; // 거리 짧을수록 우선
    }
};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> D;

    board.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

// M개의 열 중 3개 선택 (비트마스크)
vector<int> combine() {
    vector<int> result;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                int mask = (1 << i) | (1 << j) | (1 << k);
                result.push_back(mask);
            }
        }
    }
    return result;
}

// 적 한 칸 아래로 이동
void moveMonsters(vector<vector<int>>& playingBoard) {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < M; j++) {
            playingBoard[i][j] = playingBoard[i - 1][j];
        }
    }
    for (int j = 0; j < M; j++) playingBoard[0][j] = 0;
}

pair<int,int> findTarget(int archerCol, const vector<vector<int>>& board) {
    priority_queue<Target> pq;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                int dist = abs(N - i) + abs(archerCol - j); // 궁수는 (N, archerCol)에 있음
                if (dist <= D)
                    pq.push({dist, i, j});
            }
        }
    }

    if (pq.empty()) return {-1, -1};
    return {pq.top().x, pq.top().y};
}



// 해당 mask로 게임 진행
int play(int mask) {
    vector<vector<int>> playingBoard = board;
    vector<int> archers;

    // mask → 열 번호 추출
    for (int i = 0; i < M; i++) {
        if (mask & (1 << i)) archers.push_back(i);
    }

    int killCount = 0;

    // 게임 진행
    while (true) {
        // 몬스터 있는지 확인
        bool hasMonster = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (playingBoard[i][j] == 1) {
                    hasMonster = true;
                    break;
                }
            }
            if (hasMonster) break;
        }
        if (!hasMonster) break;

        // 1. 공격
        set<pair<int,int>> targets;
        for (int archer : archers) {
            pair<int,int> target = findTarget(archer, playingBoard);
            if (target.first != -1) targets.insert(target);
        }

        // 2. 제거
        for (auto [x, y] : targets) {
            if (playingBoard[x][y] == 1) {
                playingBoard[x][y] = 0;
                killCount++;
            }
        }

        // 3. 이동
        moveMonsters(playingBoard);
    }

    return killCount;
}

int solve() {
    int ans = 0;
    vector<int> comb = combine();
    for (int mask : comb)
        ans = max(ans, play(mask));
    return ans;
}

int main() {
    input();
    cout << solve() << "\n";
    return 0;
}