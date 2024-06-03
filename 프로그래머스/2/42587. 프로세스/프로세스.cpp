#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> dq;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        dq.push_back({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    
    for(int i = 0; i < priorities.size(); i++){
        
        int size = dq.size();
        int maxV = pq.top();
        pq.pop();
        answer++;
        while(size--){
            int nowIdx = dq.front().first;
            int nowValue = dq.front().second;
            dq.pop_front();
            
            if(nowValue == maxV){
                if(location == nowIdx){
                    return answer;
                }
                
                break;
            }else{
                dq.push_back({nowIdx, nowValue});
            }
            
        }
        
    }
    
    return answer;
}