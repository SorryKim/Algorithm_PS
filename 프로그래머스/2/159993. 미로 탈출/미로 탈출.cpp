#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    int moveX[4] = {0, 0, -1, 1};
    int moveY[4] = {1, -1, 0, 0};
    int sx, sy, lx, ly, ex, ey;
    vector<vector<bool>> visited;
    
    for(int i = 0; i < maps.size(); i++){
        visited.push_back(vector<bool>());
        for(int j = 0; j < maps[0].size(); j++){
            visited[i].push_back(false);
            char now = maps[i][j];
            if(now == 'S'){
                sx = i;
                sy = j;
            }
            
            if(now == 'L'){
                lx = i;
                ly = j;
            }
            
            if(now == 'E'){
                ex = i;
                ey = j;
            }
        }
    }
    
    // 시작 지점부터 레버 지점까지
    int dist1 = -1;
    
    queue<pair<pair<int,int>, int>> q;
    q.push({{sx,sy},0});
    visited[sx][sy] = true;
    
    while(!q.empty()){
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(maps[nowX][nowY] == 'L'){
            dist1 = dist;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];
            if(nextX >= 0 && nextX < maps.size() && nextY >= 0 && nextY < maps[0].size()){
                
                if(!visited[nextX][nextY]){
                    if(maps[nextX][nextY] != 'X'){
                        visited[nextX][nextY] = true;
                        q.push({{nextX, nextY}, dist + 1});
                    }
                }
            }
        }
    }
    
    // 레버 지점부터 탈출 지점까지
    int dist2 = -1;
    
    while(!q.empty())
        q.pop();
    
    q.push({{lx,ly},0});
    for(int i = 0; i < visited.size(); i++)
        for(int j = 0; j < visited[0].size(); j++)
            visited[i][j] = false;
    
    visited[lx][ly] = true;
    
    while(!q.empty()){
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(maps[nowX][nowY] == 'E'){
            dist2 = dist;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];
            if(nextX >= 0 && nextX < maps.size() && nextY >= 0 && nextY < maps[0].size()){
                
                if(!visited[nextX][nextY]){
                    if(maps[nextX][nextY] != 'X'){
                        visited[nextX][nextY] = true;
                        q.push({{nextX, nextY}, dist + 1});
                    }
                }
            }
        }
    }
    
    if(dist1 == -1 || dist2 == -1)
        answer = -1;
    else
        answer = dist1 + dist2;
    
    return answer;
}