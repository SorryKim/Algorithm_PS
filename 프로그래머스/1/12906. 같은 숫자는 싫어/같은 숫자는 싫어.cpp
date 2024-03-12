#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    
    int temp = arr[0];
    
    st.push(temp);
    
    for(auto a : arr){
        if(st.top() != a)
            st.push(a);
    }
    
    while(!st.empty()){
        answer.push_back(st.top());
        st.pop();
        
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}