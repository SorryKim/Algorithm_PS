#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto a : scoville) pq.push(a);
    
    while(pq.top() < K && pq.size() >= 2){
        answer++;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + 2 * b);
    }
    
    if(pq.top() >= K) return answer;
    else return -1;
}