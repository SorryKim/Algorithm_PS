#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    stack<string> st1, st2;
    
    for(int i = cards1.size() - 1; i >= 0; i--)
        st1.push(cards1[i]);
    for(int i = cards2.size() - 1; i >= 0; i--)
        st2.push(cards2[i]);
    
    bool flag = true;
    for(auto now : goal){
        if(!st1.empty() && now == st1.top())
            st1.pop();
        else if(!st2.empty() && now == st2.top())
            st2.pop();
        else{
            flag = false;
            break;
        }
    }
    
    answer = flag ? "Yes" : "No";
    return answer;
}