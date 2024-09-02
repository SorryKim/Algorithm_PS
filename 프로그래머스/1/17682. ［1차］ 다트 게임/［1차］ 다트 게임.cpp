#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> v;
    int idx = 0;
    int v_idx = 0;
    while(idx < dartResult.size()){
        
        // 숫자 확인
        int val = 0;
        val = dartResult[idx] -'0';
        if(dartResult[idx + 1] == '0'){
            val = 10;
            idx++;
        }
        
        idx++;
        char bonus = dartResult[idx];
        if(bonus == 'S')
            v.push_back(pow(val, 1));
        else if(bonus == 'D')
            v.push_back(pow(val, 2));
        else if(bonus == 'T')
            v.push_back(pow(val, 3));
        
        // 옵션 체크
        if(idx + 1 < dartResult.size()){
            if(dartResult[idx +1] == '*'){
                idx++;
                v[v.size() - 1] *= 2;
                if(v.size() > 1)
                   v[v.size() - 2] *= 2;
            }
            else if(dartResult[idx +1] == '#'){
                idx++;
                v[v.size() - 1] *= -1;
            }
        }
        idx++;
    }
    
    for(auto a : v)
        answer += a;
    
    return answer;
}