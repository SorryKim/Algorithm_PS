#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(auto a : arr){
        if(a % divisor == 0 || a % divisor == divisor)
            answer.push_back(a);
    }
    
    sort(answer.begin(), answer.end());
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}