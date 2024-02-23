#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i = 1; i <= 10000; i++){
        int sum = 0;
        for(int j = i; j <= 10000; j++){
            sum += j;
            
            if(sum == n){
                answer++;
                break;
            }
            
            if(sum > n)
                break;
        }
    }
    
    return answer;
}