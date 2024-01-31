#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    string answer = "";
    int val = 'A' - 'a';
    for(char ch : myString){
        
        if(isupper(ch))
            ch -= val;
        
        answer += ch;
    }
    return answer;
}