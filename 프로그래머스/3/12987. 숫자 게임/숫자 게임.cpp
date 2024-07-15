#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idx = 0;
    
    // 1 3 5 7
    // 2 2 6 8
    for(int i = 0; i < B.size(); i++){
        
        int now = B[i];
        for(int j = idx; j < A.size(); j++){
            if(now > A[j]){
                idx = j + 1;
                answer++;
                break;
            }
        }
        
    }
    
    
    return answer;
}