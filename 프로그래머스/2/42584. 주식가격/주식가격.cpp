#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;
    
    for (int i = 0; i < prices.size(); ++i) {
        // 스택이 비어있지 않고, 현재 가격이 스택 top의 가격보다 작은 경우
        while (!s.empty() && prices[s.top()] > prices[i]) {
            int index = s.top();
            s.pop();
            answer[index] = i - index;  // 떨어지지 않은 기간 계산
        }
        
        s.push(i);  // 현재 가격의 인덱스를 스택에 저장
    }

    // 스택에 남아있는 인덱스는 끝까지 가격이 떨어지지 않은 것
    while (!s.empty()) {
        int index = s.top();
        s.pop();
        answer[index] = prices.size() - index - 1; 
    }
    
    
    return answer;
}