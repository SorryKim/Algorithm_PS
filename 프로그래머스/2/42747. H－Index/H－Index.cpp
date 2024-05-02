#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int left = citations[0];
    int right = citations[citations.size() - 1];
    
    for(int i = 1; i <= right; i++){
        
        int cnt = 0;
        for(auto a : citations){
            if(a >= i)
                cnt++;
        }
        
        answer = max(answer, min(cnt, i));
    }   
    return answer;
}