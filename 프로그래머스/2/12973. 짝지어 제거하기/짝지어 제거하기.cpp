#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s){
    int answer = -1;
    
    stack<int> st;
    
    for(auto a : s){
        
        if(st.empty()){
            st.push(a);
        }else{
            if(st.top() == a)
                st.pop();
            else
                st.push(a);
        }
    }
    
    if(st.empty())
        answer = 1;
    else
        answer = 0;
    
    return answer;
}