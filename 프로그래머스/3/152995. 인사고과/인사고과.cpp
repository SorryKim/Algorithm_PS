#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<vector<int>> scores) {
    int rank = 1;
    int sum = scores[0][0] + scores[0][1];
    
    // 점수 내림차순 정렬
    auto comp = [](vector<int> v1, vector<int> v2) 
    {
        return (v1[0]+v1[1]) > (v2[0]+v2[1]);
    };
    
    sort(scores.begin()+1, scores.end(), comp);
    
    // 완호 위치 구하기
    for(int i = 1; i < scores.size(); ++i)
    {
       
        if(scores[0][0] < scores[i][0] 
          && scores[0][1] < scores[i][1])
            return -1;
        
        int score = scores[i][0] + scores[i][1];
        if(sum < score)
            rank++;
        else 
            break;
    }
    

    int range = rank;
    for(int i = 2; i < range; i++)
    {
        for(int j = 1; j < i; j++)
        {        
            if(scores[i][0] < scores[j][0] 
               && scores[i][1] < scores[j][1])
            {
                rank--;
                break;
            }
        }
    }
    
    return rank;
}