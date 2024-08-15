#include <string>
#include <vector>
#include <queue>

using namespace std;


int BFS(int x, int y, int n){
    
    bool visited[1000001] = {false};

    queue<pair<int,int>> q;
    q.push({x,0});
    visited[x] = true;
    
    while(!q.empty()){
        
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(now == y)
            return cnt;
        
        int result = 3 * now;
        if(result <= y && !visited[result]){
            visited[result] = true;
            q.push({result, cnt + 1});
        }
        
        result = 2 * now;
        if(result <= y && !visited[result]){
            visited[result] = true;
            q.push({result, cnt + 1});
        }
        
        result = now + n;
        if(result <= y && !visited[result]){
            visited[result] = true;
            q.push({result, cnt + 1});
        }
        
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    int answer = BFS(x,y,n);
    
    return answer;
}