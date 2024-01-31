#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(auto &a : arr){
        
        if(a >= 50 && a % 2 == 0)
            a /= 2;
        
        else if(a < 50 && a % 2 == 1)
            a *= 2;
    }
    
    
    return arr;
}