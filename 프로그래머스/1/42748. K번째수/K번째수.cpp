#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto a : commands){
        int start = a[0];
        int end = a[1];
        int pivot = a[2];
        vector<int> v;
        
        for(int i = start-1; i < end; i++){
            v.push_back(array[i]);
        }
        sort(v.begin(), v.end());
        
        answer.push_back(v[pivot - 1]);
        
    }
    return answer;
}