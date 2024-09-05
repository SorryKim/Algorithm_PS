#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end());
    
    for(int i = 0; i < weights.size(); i++){
        for(int j = i + 1; j < weights.size(); j++){
            
            int a = weights[i];
            int b = weights[j];
            
            if(2*a < b)
                break;
            
            if(a == b){
                answer++;
                continue;
            }
            
            // 2배
            if(2*a == 3*b || 2*a == 4*b){
                answer++;
                continue;
            }
            
            // 3배
            else if(3*a == 2*b || 3*a == 4*b){
                answer++;
                continue;
            }
            
            // 4배
            else if(4*a == 2*b || 4*a == 3*b){
                answer++;
                continue;
            }
        }
    }
    
    return answer;
}