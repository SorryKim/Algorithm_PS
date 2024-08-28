#include <string>
#include <vector>
#include <stack>

using namespace std;

string Rotate(int n, string s){
    string result = "";
    for(int i = n; i < s.size(); i++)
        result += s[i];
    
    for(int i = 0; i < n; i++)
        result += s[i];
    
    return result;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++){
        string s_now = Rotate(i,s);
        bool flag = true;
        stack<char> st;
        
        for(auto now : s_now){
            if(st.empty()){
                if(now == ']' || now == '}' || now == ')'){
                    flag = false;
                    break;
                }
            }
            
            if(now == '(' || now == '{' || now == '[')
                st.push(now);
            
            if(now == ')'){
                if(st.top() != '('){
                    flag = false;
                    break;
                }
                st.pop();
            }
            
            if(now == '}'){
                if(st.top() != '{'){
                    flag = false;
                    break;
                }
                st.pop();
            }
            
            if(now == ']'){
                if(st.top() != '['){
                    flag = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty())
            flag = false;
        
        if(flag)
            answer++;
    }
    
    return answer;
}