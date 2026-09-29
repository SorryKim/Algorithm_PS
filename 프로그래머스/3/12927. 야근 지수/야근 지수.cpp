#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(auto a : works) pq.push(a);
    
    while(n-- && !pq.empty()){
        int tmp = pq.top();
        pq.pop();
        
        if(tmp != 1) pq.push(tmp - 1);
    }
    
    while(!pq.empty()){
        int tmp = pq.top();
        answer += tmp * tmp;
        pq.pop();
    }
    
    return answer;
}