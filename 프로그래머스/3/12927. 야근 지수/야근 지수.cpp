#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.begin(), works.end(), greater<>());
    while(n--){
        if(works[0] == 0)
            break;
        works[0]--;
        
        for(int i = 1; i < works.size(); i++){
            if(works[i] > works[0]){
                int temp = works[0];
                works[0] = works[i];
                works[i] = temp;
                break;
            }
        }
    }
    
    for(auto a : works){
        answer += a*a;
    }
    
    return answer;
}