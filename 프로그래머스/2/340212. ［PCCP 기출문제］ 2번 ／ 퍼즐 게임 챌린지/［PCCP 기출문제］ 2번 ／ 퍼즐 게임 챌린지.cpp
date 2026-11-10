#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int N = diffs.size();
    
    int left = 1;
    int right = 100000;
    
    while(left <= right){
        int level = (left + right) / 2;
        long long time = times[0];
        
        for(int i = 1; i < N; i++){
            int diff = diffs[i];
            int time_cur = times[i];
            int time_prev = times[i - 1];
            
            if(level >= diff) time += time_cur;
            else{
                long long cnt = diff - level;
                long long t = time_prev + time_cur;
                time += cnt * t;
                time += time_cur;
            }
        }
        
        if(time <= limit){ 
            answer = level;
            right = level - 1;
        }
        else left = level + 1;
    }
    
    return answer;
}