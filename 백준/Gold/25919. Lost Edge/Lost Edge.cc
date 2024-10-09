#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, L, E, K;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool flag = false;

struct State {
    int x, y;
    int monster_level;

    State(int x, int y, int monster_level)
        : x(x), y(y), monster_level(monster_level) {}

    // 레벨이 낮은 몬스터부터 처리
    bool operator<(const State &other) const {
        return monster_level > other.monster_level;
    }
};

void BFS(queue<pair<int, int>>& q) {
    priority_queue<State> pq;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(map[nx][ny] == -2)
                    flag = true;
                else if(map[nx][ny] >= 0 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    pq.push(State(nx, ny, map[nx][ny]));
                }
            }
        }

        // 처리 가능한 몬스터가 있다면
        while (!pq.empty() && pq.top().monster_level < L) {
            
            State state = pq.top();
            pq.pop();

            int monster_level = state.monster_level;
            int i = state.x;
            int j = state.y;

            // 레벨 처리
            E += monster_level;
            if (E >= L) { 
                E -= L;
                L++; 
            }

            q.push({i, j});
            map[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> L >> E >> K;
    map.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));
    
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == -3) {
                map[i][j] = 0; // 시작 위치를 빈 칸으로 설정
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    BFS(q);

    if (L >= K && flag) cout << "O";
    else cout << "X";

    return 0;
}
