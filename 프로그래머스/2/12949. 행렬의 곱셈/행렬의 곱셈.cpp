#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>());
    
    for(int i = 0; i < arr1.size(); i++){
        
        auto temp1 = arr1[i];
       
        for(int j = 0; j < arr2[0].size(); j++){
            vector<int> temp2;
            int val = 0;
            for(int k = 0; k < arr2.size(); k++){
                temp2.push_back(arr2[k][j]);
            }
            
            for(int k = 0; k < temp1.size(); k++){
                val += (temp1[k] * temp2[k]);
            }
            
            answer[i].push_back(val);
        }
    }
    
    return answer;
}