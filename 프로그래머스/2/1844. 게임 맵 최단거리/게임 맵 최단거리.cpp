#include<vector>
#include <queue>
using namespace std;

bool visited[101][101] = { false, };
int moveX[4] = {1,-1,0,0};
int moveY[4] = {0,0,1,-1};

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    queue<pair<pair<int,int>,int>> q;
    
    int n = maps.size();
    int m = maps[0].size();

    q.push({{0,0},1});
    visited[0][0] = true;
    while(!q.empty()){
        int x0 = q.front().first.first;
        int y0 = q.front().first.second;
        int dist = q.front().second;
        if(x0 == n-1 && y0 == m-1)
            answer = dist;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nowX = x0 + moveX[i];
            int nowY = y0 + moveY[i];
            
            if(nowX >= 0 && nowX < n && nowY >= 0 && nowY < m){
                if(!visited[nowX][nowY] && maps[nowX][nowY] != 0){
                    
                    visited[nowX][nowY] = true;
                    q.push({{nowX, nowY}, dist + 1});
                }
            }
        }
        
    }
    
    
    
    return answer;
}