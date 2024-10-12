#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int N, M, P;
int Boss_HP;
char map[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
unordered_map<char, int> player_dps;
unordered_map<char, int> arrival_time;
unordered_map<char, bool> arrived;

void Input(){

    cin >> M >> N >> P;
    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++)
            map[i][j] = s[j];
    }
    for(int i = 0; i < P; i++){
        char name;
        int dps;
        cin >> name >> dps;
        arrived[name] = false;
        player_dps[name] = dps;
    }
    cin >> Boss_HP;
}

int BFS(int startX, int startY){
    queue<pair<int,pair<int,int>>> q;
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    visited[startX][startY] = true;
    q.push({0,{startX,startY}});

    while(!q.empty()){
        int time = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(map[x][y] == 'B')
            return time;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < M && ny >= 0 && ny < N){
                if(visited[nx][ny])
                    continue;
                if(map[nx][ny] == 'X')
                    continue;
                visited[nx][ny] = true;
                q.push({time + 1, {nx, ny}});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();

    // 각 플레이어마다 BFS하여 시간 체크
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            char now = map[i][j];
            if(now >= 'a' && now <= 'z'){
                int time = BFS(i,j);
                arrival_time[now] = time;
            }
        }
    }

    int time = 0;
    while(Boss_HP > 0){
        time++;

        for(auto player : arrival_time){
            if(player.second == time)
                arrived[player.first] = true;
        }
        
        // 1초 후 공격가능하므로 도착하자마자는 공격못함
        for(auto player : player_dps){
            if(arrived[player.first] && arrival_time[player.first] <= time - 1)
                Boss_HP -= player.second;
        }
    }

    int answer = 0;
    for(auto player : arrival_time)
        if(arrival_time[player.first] < time)
            answer++;

    cout << answer << '\n';

    return 0;
}
