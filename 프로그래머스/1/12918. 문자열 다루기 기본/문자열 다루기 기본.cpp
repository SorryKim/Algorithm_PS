#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() != 4 && s.size() != 6)
        return false;
    
    for(auto now : s){
        
        if(now < '0' || now >'9')
            return false;
    }
    
    return answer;
}