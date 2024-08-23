#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int len = s.size();
    
    for(int i = 0; i < len; i++){
        if(s[i] == ' ')
            continue;
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = (s[i]  - 'a' + n) % 26 + 'a';
        }else{
            s[i] = (s[i] - 'A' + n) % 26 + 'A';
        }
        
    }
    
    answer = s;
    return answer;
}