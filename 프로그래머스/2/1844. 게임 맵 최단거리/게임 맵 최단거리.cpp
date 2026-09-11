#include <vector>
#include <queue>

using namespace std;

struct State{
    int x, y, cnt;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(vector<vector<int>> &maps){
 
    int N = maps.size();
    int M = maps[0].size();
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<State> q;
    q.push({0,0,1});
    visited[0][0] = true;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        
        if(x == N - 1 && y == M - 1) return cnt;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(visited[nx][ny] || maps[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                q.push({nx, ny, cnt + 1});
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = BFS(maps);
    return answer;
}