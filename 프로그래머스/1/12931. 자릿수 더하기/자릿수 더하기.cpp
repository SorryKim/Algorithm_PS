#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string num = to_string(n);
    
    for(auto a : num){
        answer += a - '0';
    }

    return answer;
}