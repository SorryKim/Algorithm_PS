#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Func(char ch, vector<char> &v){
    
    for(int i = 0; i < v.size(); i++){
        if(ch == v[i])
            return i;
    }
    
    return -1;
}
string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> v;
    
    for(int i = 'a'; i <= 'z'; i++){
        bool flag = true;
        for(auto now : skip){
            if(i == now){
                flag = false;
                break;
            }
        }
        if(flag)
            v.push_back(i);
    }
    
    for(int i = 0; i < s.size(); i++){
        
        int idx = Func(s[i], v);
        idx = (idx + index) % v.size();
        s[i] = v[idx];
    }
    
    answer = s;
    return answer;
}