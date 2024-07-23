#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    
    for(int i = 0; i < numbers.size(); i++){
        
        int a = numbers[i];
        for(int j = i + 1; j < numbers.size(); j++){
            int b = numbers[j];
            s.insert(a+b);
        }
    }
    
    for(auto a : s){
        answer.push_back(a);
    }
    
    //sort(answer.begin(), answer.end());
    return answer;
}