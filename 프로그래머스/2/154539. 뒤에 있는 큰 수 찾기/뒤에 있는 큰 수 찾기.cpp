#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    
    for(int i = 0; i < numbers.size(); i++)
        answer.push_back(-1);
    
    
    for(int i = 0; i < numbers.size(); i++){
        
        int now = numbers[i];
        
        while(!st.empty() && now > numbers[st.top()]){
            
            answer[st.top()] = now;
            st.pop();
        }
        st.push(i);
    }
    
    return answer;
}