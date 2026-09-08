#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> mp;
    for(string s : participant){
        mp[s]++;
    }
    
    for(string s : completion){
        mp[s]--;
    }
    
    for(auto a : mp){
        if(a.second == 1){
            answer = a.first;
            break;
        }
    }
    
    return answer;
}