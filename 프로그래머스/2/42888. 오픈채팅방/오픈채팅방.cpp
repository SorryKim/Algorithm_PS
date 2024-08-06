#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> Split(string s){
    
    vector<string> result;
    string temp = "";
    
    for(auto a : s){
        if(a == ' '){
            result.push_back(temp);
            temp = "";
        }else{
            temp += a;
        }
    }
    
    result.push_back(temp);
    
    return result;
}

vector<string> solution(vector<string> record) {
    
    vector<string> answer;
    unordered_map<string, string> table;
    vector<pair<int, string>> q;
    
    for(string s : record){
        
        vector<string> temp = Split(s);
        string cmd = temp[0];
        string uid = temp[1];
        
        if(cmd == "Enter"){
            if(table.find(uid) == table.end())
                table.insert({uid, temp[2]});
            else
                table[uid] = temp[2];
            q.push_back({0, uid});
        }
        
        if(cmd == "Leave"){
            string name = table[uid];
            q.push_back({1, uid});
        }
        
        if(cmd == "Change"){
            table[uid] = temp[2];
        }
        
    }
    
    for(auto a : q){
        
        int cmd = a.first;
        string name = table[a.second];
        
        if(cmd == 0)
            answer.push_back(name + "님이 들어왔습니다.");
        else
            answer.push_back(name + "님이 나갔습니다.");
    }
    
    
    return answer;
}