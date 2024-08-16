#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string temp = "";
    
    // 3진법 변환, 뒤집기까지 완료
    while(n != 0){
        temp += to_string(n % 3);
        n /= 3;
    }
    
    // 10진법으로 변환
    
    int cnt = 0;
    for(int i = temp.size() - 1; i >=0; i--){
        
        answer += (temp[i] - '0') * pow(3,cnt);
        cnt++;
    }
    
    
    return answer;
}