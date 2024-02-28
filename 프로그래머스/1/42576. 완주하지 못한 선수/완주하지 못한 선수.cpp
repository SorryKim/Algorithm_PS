#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> myMap;
    
    for (string s : participant) {
       myMap[s]++;
    }
    

    for (string s : completion) {
        myMap[s]--;
    }
    
    
    for (string s : participant) {
       if(myMap.count(s) > 0 && myMap[s] > 0){
           answer = s;
           break;
       }
    }

    return answer;
}
