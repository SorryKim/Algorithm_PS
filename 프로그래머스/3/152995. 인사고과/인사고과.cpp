#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 

bool cmp(const vector<int>& a, const vector<int>& b){
    
    return (a[0] + a[1]) > (b[0] + b[1]);    
}


int solution(vector<vector<int>> scores) {
    int rank = 1;
    
    
    sort(scores.begin()+1, scores.end(), cmp);
    
    // 완호 위치 구하기
    for(int i = 1; i < scores.size(); ++i)
    {
       
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1])
            return -1;
        
        int score = scores[i][0] + scores[i][1];
        int sum = scores[0][0] + scores[0][1];
        
        if(sum < score)
            rank++;
        else 
            break;
    }
    
    int range = rank;
    for(int i = 2; i < range; i++){
        for(int j = 1; j < i; j++){        
            if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]){
                rank--;
                break;
            }
        }
    }
    
    return rank;
}