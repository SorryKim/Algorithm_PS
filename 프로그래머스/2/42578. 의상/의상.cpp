#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> table;
    
    for(auto a : clothes){
        string now = a[1];
        
        if(table.find(now) == table.end()){
            table.insert({now, 1});
        }else{
            table[now]++;
        }
    }
    
    
    for(auto a : table){
        int cnt = a.second + 1;
        answer *= cnt;
    }
    
    return answer - 1;
}