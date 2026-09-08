#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, left;
    int N = progresses.size();
    
    for(int i = 0; i < N; i++){  
        int cnt = 0;
        int temp = progresses[i];
        while(temp < 100){
            cnt++;
            temp += speeds[i];
        }
        left.push_back(cnt);
    }
    
    queue<int> q;
    
    for(int i = 0; i < N; i++){
        int now = left[i];
        
        if(q.empty()){
            q.push(now);
            continue;
        }
        
        // 1. 작거나 같은 경우
        if(now <= q.front()) q.push(now);
        
        // 2. now가 큰 경우
        else{
            int cnt = 0;
            while(!q.empty() && q.front() < now){
                cnt++;
                q.pop();
            }
            answer.push_back(cnt);
            q.push(now);
        }
    }
    
    // 남아있는 Task 처리
    answer.push_back(q.size());
    
    return answer;
}