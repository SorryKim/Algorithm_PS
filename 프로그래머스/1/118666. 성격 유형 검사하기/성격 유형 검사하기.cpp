#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int N = survey.size();
    
    //    +  -
    // 0: R, T
    // 1: C, F
    // 2: J, M
    // 3: A, N
    vector<int> mbti(4, 0);
    
    for(int i = 0; i < N; i++){
        char c1 = survey[i][0];
        char c2 = survey[i][1];
        
        int val = choices[i] - 4;
        
        // 1번 유형
        if(c1 == 'R') mbti[0] -= val;
        if(c1 == 'T') mbti[0] += val;
        
        // 2번 유형
        if(c1 == 'C') mbti[1] -= val;
        if(c1 == 'F') mbti[1] += val;
        
        // 3번 유형
        if(c1 == 'J') mbti[2] -= val;
        if(c1 == 'M') mbti[2] += val;
        
        // 4번 유형
        if(c1 == 'A') mbti[3] -= val;
        if(c1 == 'N') mbti[3] += val;
    }
    
    if(mbti[0] >= 0) answer += "R";
    else answer += "T";
    
    if(mbti[1] >= 0) answer += "C";
    else answer += "F";
    
    if(mbti[2] >= 0) answer += "J";
    else answer += "M";
    
    if(mbti[3] >= 0) answer += "A";
    else answer += "N";
    
    //for(int val : mbti) cout << val << endl;
    
    return answer;
}