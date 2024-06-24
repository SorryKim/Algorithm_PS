#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool arr[10] = {false, };
    
    for(auto a : numbers){
        arr[a] = true;
    }
    
    for(int i = 1; i <= 9; i++){
        if(!arr[i])
            answer += i;
    }
    
    return answer;
}