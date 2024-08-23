#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> table;
    bool flag = true;
    table.insert(words[0]);
    
    for(int i = 1; i < words.size(); i++){
        string word = words[i];
        string before = words[i - 1];
        
        // 끝말잇기 여부
        // 끝말잇기가 안될 경우
        if(word[0] != before[before.size() - 1]){
            int who = i % n + 1;
            int when = ceil((double)(i + 1) / (double)n);
            answer.push_back(who);
            answer.push_back(when);
            return answer;
        }
        
        // 단어 사용여부 체크
        // 단어 사용한적이 있으면
        if(table.find(word) != table.end()){
            int who = i % n + 1;
            int when = ceil((double)(i + 1) / (double)n);
            answer.push_back(who);
            answer.push_back(when);
            return answer;
        }else
            table.insert(word);
    }
    
 
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}