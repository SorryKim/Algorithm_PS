#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[100][100];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) board[i][j] = s[j];
    }

    return;
}

int bfs(int x, int y, vector<vector<bool>> &visited){
    
    char team = board[x][y];
    int cnt = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while(!q.empty()){

        cnt++;
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if(nx >= 0 && nx < M && ny >= 0 && ny < N){
                if(!visited[nx][ny] && board[nx][ny] == team){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return cnt * cnt;
}

void solve() {
    
    int cntW = 0;
    int cntB = 0;
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                int cnt = bfs(i, j, visited);
                if(board[i][j] == 'W') cntW += cnt;
                else cntB += cnt;
                // cout << "현재 cnt 값 " << cntW << " " << cntB << "\n";
            }
        }
    }

    cout << cntW << " " << cntB << "\n";
    return;
}

int main() {
    input();
    solve();

    return 0;
}