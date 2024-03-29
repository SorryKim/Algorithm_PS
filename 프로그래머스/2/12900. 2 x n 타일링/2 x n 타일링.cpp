#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int DP[60001];
    DP[0] = 0;
    DP[1] = 1;

    DP[2] = 2;
    
    for(int i = 3; i <= 60000; i++){
        // DP[3] = DP[1] + 1 + DP[2];
        DP[i] = (DP[i - 1] + DP[i - 2] )% 1000000007;
    }
    
    answer = DP[n];
    return answer;
}