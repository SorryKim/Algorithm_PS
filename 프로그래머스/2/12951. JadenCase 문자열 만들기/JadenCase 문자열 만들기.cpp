#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(const string& str){
    vector<string> v;
    stringstream ss(str);
    string s;
    
    while(ss >> s){
        v.push_back(s);
    }
    
    return v;
}

string solution(string s) {
    
    string answer = "";
    bool flag = false;

    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == ' ') 
            flag = false;
        else{
            s[i] = toupper(s[i]);
            
            if(flag) 
                s[i] = tolower(s[i]);
            
            flag = true;
        }
    }

    answer = s;
    return answer;
}