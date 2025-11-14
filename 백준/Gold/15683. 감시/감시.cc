#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CCTV{
    int x, y, type;
};

int N, M;
int ans = 1e9;
vector<vector<int>> board;
vector<CCTV> cctv;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<vector<int>>> cctvDir = {
    {},
    {{0}, {1}, {2}, {3}},               // 1번
    {{0,2}, {1,3}},                     // 2번
    {{0,1}, {1,2}, {2,3}, {3,0}},       // 3번
    {{0,1,2}, {1,2,3}, {2,3,0}, {3,0,1}}, // 4번
    {{0,1,2,3}}                         // 5번
};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.resize(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5){
                cctv.push_back({i,j, board[i][j]});
            }
        }
    }

}

void watch(int x, int y, int dir, vector<vector<int>>& temp){
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >= N || y < 0 || y >= M) return;
        if(temp[x][y] == 6) return;
        if(temp[x][y] == 0) temp[x][y] = -1;
    }

}

// 현재 방향조합으로 생기는 사각지대 수 계산
int calc(vector<int> &dirs){

    int result = 0;
    vector<vector<int>> temp = board;
    
    // 1. 감시가능 지역 표시
    for(int i = 0; i < cctv.size(); i++){
        CCTV now = cctv[i];
        int type = now.type;

        for(int d : cctvDir[type][dirs[i]]){
            watch(now.x, now.y, d, temp);
        }
    }

    // 사각지대 계산
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(temp[i][j] == 0) result++;
        }
    }

    return result;
}

// 방향 조합
void dfs(int idx, vector<int> dirs){

    if(idx == dirs.size()){
        ans = min(ans, calc(dirs));
        return;
    }

    int type = cctv[idx].type;
    int cnt = cctvDir[type].size();

    for(int i = 0; i < cnt; i++){
        dirs[idx] = i;
        dfs(idx + 1, dirs);
    }
}

void solve(){
    vector<int> v(cctv.size(), 0);
    dfs(0, v);
    return;
}

int main(){
    input();
    solve();
    cout << ans << "\n";

    return 0;
}