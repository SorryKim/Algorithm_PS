#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int idx = 0;
    if(ext == "date")
        idx = 1;
    else if(ext == "maximum")
        idx = 2;
    else if(ext == "remain")
        idx = 3;
    
    for(auto now : data){
        
        int val = now[idx];
        if(val <= val_ext){
            answer.push_back(now);
        }
    }
    
    if(sort_by == "code")
        idx = 0;
    else if(sort_by == "date")
        idx = 1;
    else if(sort_by == "maximum")
        idx = 2;
    else if(sort_by == "remain")
        idx = 3;
    
    sort(answer.begin(), answer.end(), [idx](vector<int> v1, vector<int> v2) {
        return v1[idx]  < v2[idx];
    });
    
    return answer;
}