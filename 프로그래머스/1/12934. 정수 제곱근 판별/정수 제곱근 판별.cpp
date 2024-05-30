#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    
    for(long long i = 1; i <= sqrt(50000000000000); i++){
        
        long long now = i * i;
        if(now == n){
            answer = (i + 1)*(i + 1);
            break;
        }
    }
    
    
    return answer;
}