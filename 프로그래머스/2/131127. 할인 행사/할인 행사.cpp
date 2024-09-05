#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string,int> table;
    
    for(int i = 0; i < want.size(); i++){
        table[want[i]] = number[i];
    }
    
    for(int i = 0; i + 10 <= discount.size(); i++){
        
        unordered_map<string, int> temp = table;
        
        for(int j = i; j < i + 10; j++) {
            string now = discount[j];
            temp[now]--; 
            if(temp[now] == 0) {
                temp.erase(now); 
            }
        }
        
        if(temp.empty())
            answer++;
    }
    
    return answer;
}