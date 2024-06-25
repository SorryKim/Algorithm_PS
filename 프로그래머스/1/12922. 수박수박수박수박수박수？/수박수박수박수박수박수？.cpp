#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i = 1; i <= n; i++){
        (i % 2 == 1) ? answer += "수" : answer += "박";
    }
    return answer;
}