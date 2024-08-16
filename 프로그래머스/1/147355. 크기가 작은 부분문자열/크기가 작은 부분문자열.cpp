#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int len = p.size();
 
    for(int i = 0; i + len <= t.size(); i++){
        string temp = "";
        for(int j = i; j < i + len; j++)
            temp += t[j];
        
        if(temp <= p){
            answer++;
        }
        
    }
    
    return answer;
}