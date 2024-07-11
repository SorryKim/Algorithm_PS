#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void clear(string skill, unordered_map<char, bool> &table ){
    
    table[skill[0]] = true;
    for(int i = 1; i < skill.size(); i++){
        table[skill[i]] = false;
    }
    
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, bool> table;
    
    table.insert({skill[0], true});
    for(int i = 1; i < skill.size(); i++){
        char now = skill[i];
        table.insert({now, false});
    }
    
    
    for(auto now : skill_trees){
        
        bool flag = true;
        clear(skill, table);
        for(int i = 0;i < now.size(); i++){
            char now_skill = now[i];
            
            if(table.find(now_skill) != table.end()){
                
                if(table[now_skill]){
                    for(int i = 0; i < skill.size(); i++){
                        if(skill[i] == now_skill){
                            if(i + 1 < skill.size()){
                                table[skill[i+1]] = true;
                            }
                        }
                    }
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
            answer++;        
    }
    
    
    return answer;
}