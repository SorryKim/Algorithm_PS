#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1, p2, p3;
    
    for(int i = 0; i <= 2000; i++){
        p1.push_back(1);
        p1.push_back(2);
        p1.push_back(3);
        p1.push_back(4);
        p1.push_back(5);
        
        p2.push_back(2);
        p2.push_back(1);
        p2.push_back(2);
        p2.push_back(3);
        p2.push_back(2);
        p2.push_back(4);
        p2.push_back(2);
        p2.push_back(5);
        
        p3.push_back(3);
        p3.push_back(3);
        p3.push_back(1);
        p3.push_back(1);
        p3.push_back(2);
        p3.push_back(2);
        p3.push_back(4);
        p3.push_back(4);
        p3.push_back(5);
        p3.push_back(5);
    }
    
    
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    for(int i =0; i < answers.size(); i++){
        int now = answers[i];
        if(now == p1[i])
            cnt1++;
        
        if(now == p2[i])
            cnt2++;
        
        if(now == p3[i])
            cnt3++;
        
    }
    
    int result = max(cnt1, max(cnt2, cnt3));
    
    if(result == cnt1)
        answer.push_back(1);
    
    if(result == cnt2)
        answer.push_back(2);
    
    if(result == cnt3)
        answer.push_back(3);
    
    return answer;
}