#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;
    bool b = false;
    
    for(auto a : scoville){
        pq.push(a);
    }
    
    while(pq.size() >= 2){
        
        if(pq.top() >= K){
            b = true;
            break;
        }
        
        cnt++;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a + 2*b);
    }
    
    
    if(pq.top() >= K)
        b = true;
    
    answer = b ? cnt : -1;
    return answer;
}