#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string words[4] = {"aya", "ye", "woo", "ma"};
    
    for(auto& word : babbling) {
        string lastWord = "";
        bool flag = true;
        int start = 0;
        
        while(start < word.size()) {
            bool matched = false;
            
            for(int i = 0; i < 4; i++) {
                
                // 단어와 일치여부와 중복 사용 여부 체크
                if(word.substr(start, words[i].size()) == words[i] && words[i] != lastWord) {
                    lastWord = words[i];
                    start += words[i].size();
                    matched = true;
                    break;
                }
            }
            
            if(!matched) {
                flag = false;
                break;
            }
        }
        
        if(flag) 
            answer++;
    }
    
    return answer;
}
