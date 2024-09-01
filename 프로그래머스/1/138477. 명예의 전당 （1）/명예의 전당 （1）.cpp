#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(auto now : score){
        if(pq.size() < k)
            pq.push(now);
        else{
            if(pq.top() < now){
                pq.pop();
                pq.push(now);
            }
        }
        
        answer.push_back(pq.top());
    }
    
    return answer;
}