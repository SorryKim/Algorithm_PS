#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(int idx, int val, const vector<int> &numbers, int target){
    
    if(idx >= numbers.size()){
        if(val == target)
            answer++;
        
        return;
    }
    
    
    int now = numbers[idx];
    
    DFS(idx + 1, val + now, numbers, target);
    DFS(idx + 1, val - now, numbers, target);
    
}

int solution(vector<int> numbers, int target) {
    
    DFS(0,0,numbers,target);
    return answer;
}