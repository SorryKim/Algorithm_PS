#include <string>
#include <vector>
#include <iostream>

using namespace std;

string check(string s){
    
    if(s == "zero")
        return "0";
    
    if(s == "one")
        return "1";
    
    if(s == "two")
        return "2";
    
    if(s == "three")
        return "3";
    
    if(s == "four")
        return "4";
    
    if(s == "five")
        return "5";
    
    if(s == "six")
        return "6";
    
    if(s == "seven")
        return "7";
    
    if(s == "eight")
        return "8";
    
    if(s == "nine")
        return "9";
    
    return "false";
    
}

int solution(string s) {
    int answer = 0;
    string ans = "";
    string temp = "";
    
    for(int i = 0; i < s.length(); i++){
        temp += s[i];
        if(s[i] >= '0' && s[i] <= '9'){
            ans += s[i];
            temp = "";
            continue;
        }
        string result = check(temp);
        if(result != "false"){
            ans += result;
            temp = "";
        }
        
    }
    cout << ans;
    answer = stoi(ans);
    return answer;
}