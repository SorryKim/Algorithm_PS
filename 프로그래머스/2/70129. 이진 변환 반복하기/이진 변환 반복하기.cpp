#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string intToBinaryString(int n) {
    
    string result = "";
    if (n == 0) 
        return "0";
    
    while (n != 0) {
        result += (n % 2) ? '1' : '0';
        n /= 2;
    }
    reverse(result.begin(), result.end()); // 2진수 문자열을 뒤집습니다
    return result;
}


vector<int> func(string s){
    
    vector<int> answer;
    string now = s;
    int cnt = 0;
    int deletedZero = 0;
    
    while(now != "1"){
        cnt++;
        
        // 1. x의 모든 0을 제거합니다.
        string temp = "";
        for(auto a : now){
            if(a == '1')
                temp += a;
            else
                deletedZero++;
        }

        // 2. x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.
        int target = temp.size();
        now = intToBinaryString(target);
    }
    
    answer.push_back(cnt);
    answer.push_back(deletedZero);
    return answer;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    answer= func(s);
    
 
    return answer;
}