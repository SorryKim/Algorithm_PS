#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto a : myString){
        
        answer += toupper(a);
    }
    return answer;
}