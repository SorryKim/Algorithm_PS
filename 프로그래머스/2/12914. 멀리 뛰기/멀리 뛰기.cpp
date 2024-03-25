#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long DP[2001] = {0, };
    DP[0] = 1;
    DP[1] = 1;
    
    for(int i = 2; i <= 2000; i++){
        DP[i] = (DP[i - 2] + DP[i - 1]) % 1234567;
    }
    
    answer = DP[n];
    return answer;
}