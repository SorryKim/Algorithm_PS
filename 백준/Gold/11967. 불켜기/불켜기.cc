#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int N, M;
vector<vector<vector<pair<int,int>>>> switches;
vector<vector<bool>> graph;
vector<vector<bool>> visited;

void Input(){

    cin >> N >> M;
    switches.resize(N + 1, vector<vector<pair<int,int>>>(N+1));
    graph.resize(N+1, vector<bool>(N+1, false));
    visited.resize(N + 1, vector<bool>(N + 1, false));

    for(int i = 1; i <= M; i++){
        int x, y, a, b;

        cin >> x >> y >> a >> b;
        switches[x][y].push_back({a,b});
    }
}

// 방문 배열 초기화
void Clear(){

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            visited[i][j] = false;
        }
    }

}

int BFS(){

    int cnt = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    queue<pair<int,int>> q;
    graph[1][1] = true;
    q.push({1,1});
    visited[1][1] = true;

    while(!q.empty()){

        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        
        bool flag = false;

        // 해당방에 존재하는 스위치 키기
        for(auto temp : switches[now_x][now_y]){
            // 이미 켜져있는 경우 넘김
            if(graph[temp.first][temp.second]) continue;
            
            graph[temp.first][temp.second] = true;
            flag = true;
        }

        // 스위치를 킨 경우 방문배열 초기화
        if(flag) Clear();

        // 움직일 수 있는 방 체크...
        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;

            if(graph[nx][ny] && !visited[nx][ny]) {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }

        }
    }

    // 불켜진 방갯수 세기
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(graph[i][j]) cnt++;
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    cout << BFS() << "\n";

    return 0;
}