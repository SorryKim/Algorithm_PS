#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for(int i = 0; i < land.size(); i++){
        
        if(i == 0)
            continue;
        
        for(int j = 0; j < land[i].size(); j++){
            int temp = 0;
            for(int k = 0; k < 4; k++){
                if(j == k)
                    continue;
                
                temp = max(temp, land[i -1][k]);
            }
            
            land[i][j] += temp;
            
            
            
        }
        
    }
    
    vector<int> answers = land[land.size() - 1];
    
    for(auto a : answers)
        answer = max(a, answer);
    
    
    return answer;
}