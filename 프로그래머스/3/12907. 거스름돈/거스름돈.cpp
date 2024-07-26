#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DP[100001] = { 0, };

int solution(int n, vector<int> money) {
    int answer = 0;
    
    DP[0] = 1;
    
    for(auto coin : money){
        for(int i = coin; i <= n; i++){
            DP[i] += DP[i - coin];
            DP[i] %= 1000000007;
        }
    }
    
    return DP[n];
}