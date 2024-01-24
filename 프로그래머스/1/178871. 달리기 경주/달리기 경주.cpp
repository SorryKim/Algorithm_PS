#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<int, string> map1;
    map<string, int> map2;
    
    for(int i = 0; i < players.size(); i++)
    {
        map1[i] = players[i];
        map2[players[i]] = i;
    }
    
    for(int i=0;i<callings.size();i++)
    {
        string calledName = callings[i];
        int idx = map2[calledName];
        
        map1[idx] = map1[idx - 1];
        map1[idx-1] = calledName;
        
        map2[map1[idx]] = idx;
        map2[calledName] = idx - 1;
        
    }
    
    for(auto a : map1){
        answer.push_back(a.second);
    }
  

    return answer;
}