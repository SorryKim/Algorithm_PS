#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 987654321;
    
    // key - value
    deque<pair<int,int>> dq;
    
    for(int i = 0; i < stones.size(); i++){
        
        if(dq.empty()){
            dq.push_back({i, stones[i]});
        }
        else{
            
            while(!dq.empty() && dq.back().second < stones[i]){
                dq.pop_back();
            }
            
            dq.push_back({i, stones[i]});
            
            if(i - dq.front().first == k)
                dq.pop_front();
            
        }
        
        if(i + 1 >= k)
            answer = min(answer, dq.front().second);
        
    }
    
    return answer;
}