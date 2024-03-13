#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<int> graph[101];

int BFS(int v1, int v2){
    
    queue<int> q;
    
    bool visited[101] = { false, };
    visited[v1] = true;
    visited[v2] = true;
    int cnt = 1;
    int cnt1, cnt2;
    
    q.push(v1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto a : graph[now]){
            int next = a;
            if(!visited[a]){
                cnt++;
                visited[a] = true;;
                q.push(a);
            }
        }
    }
    cnt1 = cnt;
    cnt = 1;
    q.push(v2);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto a : graph[now]){
            int next = a;
            if(!visited[a]){
                cnt++;
                visited[a] = true;;
                q.push(a);
            }
        }
    }
    
    cnt2 = cnt;
    
    
    return abs(cnt1 - cnt2);
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    // 그래프 생성
    for(auto a : wires){
        int v1 = a[0];
        int v2 = a[1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    for(auto a : wires){
        int v1 = a[0];
        int v2 = a[1];
        
        answer = min(answer, BFS(v1,v2));
    }
    
    
    return answer;
}