#include <string>
#include <vector>

using namespace std;

int N;
int answer = 0;
int TARGET;

void DFS(int v, int depth, vector<int> &numbers){
    
    if(depth == N){
        if(v == TARGET) answer++;
        return;
    }
    
    DFS(v + numbers[depth], depth + 1, numbers);
    DFS(v - numbers[depth], depth + 1, numbers);
    
    return;
}


int solution(vector<int> numbers, int target) {
    N = numbers.size();
    TARGET = target;
    DFS(0, 0, numbers);
    
    return answer;
}