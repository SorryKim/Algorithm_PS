#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for(char ch : my_string){
        if(string(1, ch) == letter) continue;
        answer += ch;
    }
    
    return answer;
}