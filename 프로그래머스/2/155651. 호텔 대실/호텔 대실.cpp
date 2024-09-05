#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    
    return p1.first < p2.first;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    // 분으로 변환 작업
    vector<pair<int,int>> times;
    for(auto now : book_time){
        
        string start = now[0];
        string end = now[1];
        
        int startH = stoi(start.substr(0, 2));
        int startM = stoi(start.substr(3, 2));
        int endH = stoi(end.substr(0, 2));
        int endM = stoi(end.substr(3, 2));
        
        times.push_back({startH * 60 + startM, endH * 60 + endM});
    }
    
    // 시작 시간순으로 정렬
    sort(times.begin(), times.end(), cmp);
    
    queue<pair<int,int>> q;
    for(auto a : times)
        q.push(a);
    
    
    vector<int> rooms;
    while(!q.empty()){
        
        
        pair<int,int> now = q.front();
        
        q.pop();
        
        bool flag = false;
        
        // 끝나는 시간기준 오름차순 정렬
        sort(rooms.begin(), rooms.end());
        for(int i = 0; i < rooms.size(); i++){
            
            if(rooms[i] + 10 <= now.first){
                flag = true;
                rooms[i] = now.second;
                break;
            }
        }
        
        if(!flag)
            rooms.push_back(now.second);
        
        // 방이 필요한 최대 순간 체크
        answer = max(answer, (int)rooms.size());
    }
    
    
    return answer;
}