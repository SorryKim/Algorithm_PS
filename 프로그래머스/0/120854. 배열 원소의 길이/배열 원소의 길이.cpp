#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    
    for(auto a : strlist){
        answer.push_back(a.size());
    }
    return answer;
}