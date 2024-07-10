#include <string>
#include <vector>


using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int num = s / n;
    int div = s % n;
    
    if(num == 0){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0; i < n - div; i++)
        answer.push_back(num);
    
    
    for(int i = 0; i < div; i++)
        answer.push_back(num + 1);
    
    return answer;
}