#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string s = to_string(x);
    int div = 0;
    for(int i = 0; i < s.size(); i++){
        div += s[i] - '0';
    }
    
    answer = (x % div) ? false : true;
    return answer;
}