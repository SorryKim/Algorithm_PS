#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> score;
    
    for(int i = 0; i < name.size(); i++){
        string s = name[i];
        int val = yearning[i];
        score.insert({s,val});
    }
    
    for(auto now : photo){
        int sum = 0;
        for(auto people : now){
            sum += score[people];
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}