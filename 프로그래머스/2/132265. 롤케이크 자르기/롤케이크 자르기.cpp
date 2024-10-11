#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> setA, setB;
    
    for(int i = 0; i < topping.size(); i++){
        setA[topping[i]]++;
    }
    
    
    for(int i = topping.size() - 1; i > 0; i--){
        
        int now = topping[i];
        setA[now]--;
        if(setA[now] == 0)
            setA.erase(now);
        setB[now]++;
        if(setA.size() == setB.size())
            answer++;
    }
    
    
    return answer;
}