#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++){
        char now = s[i];
        if(now == '('){
            st.push(now);
        }
        else if(now == ')'){
            if(st.empty())
                return false;
            else
                st.pop();
        }
    }
    
    if(st.empty())
        return true;
    else
        return false;
}