#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(24, 0);
    
    for(int time = 0; time < 24; time++){
        
        int player = players[time];
        int required = player / m;
        
        // 1. 서버 증설 필요
        if(required > server[time]){
            int cnt = required - server[time];
            for(int i = 0; i < k; i++){
                if(time + i < 24){
                    server[time + i] += cnt;
                }
            }
            
            answer += cnt;
        }
    }
    
    return answer;
}