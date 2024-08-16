#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void DFS(int start, int depth, vector<int> temp, vector<int> &number){
    
    if(depth == 3){
        int sum = 0;
        for(auto a : temp)
            sum += a;
        
        if(sum == 0)
            answer++;
          
        return;
    }
    
    for(int i = start; i < number.size(); i++){
        temp.push_back(number[i]);
        DFS(i + 1, depth + 1, temp, number);
        temp.pop_back();
    }
    
}

int solution(vector<int> number) {
    
    
    DFS(0 , 0, vector<int>(), number);
    
    return answer;
}