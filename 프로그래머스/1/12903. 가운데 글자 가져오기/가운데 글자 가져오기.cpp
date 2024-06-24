#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int target = s.size() / 2;
    if(s.size() % 2 == 0){
        answer += s[target - 1];
        answer += s[target];
    }else{
         answer += s[target];
    }
    
    
    return answer;
}