#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
char graph[1001][1001];
int visited[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int answer = 0;

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            graph[i][j] = s[j];
            visited[i][j] = 0; // 방문 초기화
        }
    }
}

int getDir(char ch){
    if(ch == 'U') return 0;
    else if(ch == 'D') return 1;
    else if(ch == 'L') return 2;
    else if(ch == 'R') return 3;

    return -1;
}

void DFS(int x, int y){
    visited[x][y] = 1;
    int dir = getDir(graph[x][y]);
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(visited[nx][ny] == 0) DFS(nx, ny);
    if(visited[nx][ny] == 1) answer++;

    visited[x][y] = 2;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] != 0) continue;
            DFS(i, j);
        }
    }

    cout << answer << '\n';

    return 0;
}
