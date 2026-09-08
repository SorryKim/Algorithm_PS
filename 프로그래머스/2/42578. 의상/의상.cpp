#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> mp;
    
    for(auto now : clothes){
        string category = now[1];
        mp[category]++;
    }
    
    for(auto var : mp){
        answer *= (var.second + 1);
    }
    return answer - 1;
}