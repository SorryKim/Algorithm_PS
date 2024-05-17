#include <string>
#include <vector>

using namespace std;

int func(int num){
    int cnt = 0;
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    
    for(auto a : binary){
        if(a == '1')
            cnt++;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    bool b = false;
    int now = n;
  
    
    while(!b){
        now++;
        
        if(func(now) == func(n)){
                answer = now;
            break;
        }
        
    }
    
    return answer;
}