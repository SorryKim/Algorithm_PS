#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> v;
    char temp = ' ';
    string str = "";
    int a = 0, b = 0;
    
    for(int i = 0; i < s.size(); i++){
        
        
        char now = s[i];
        str += now;
        if(temp == ' '){
            temp = now;
            a++;
        }
        else{
            if(now != temp)
                b++;
            else
                a++;
            
            if(a == b){
                answer++;
                a = 0;
                b = 0;
                temp = ' ';
                v.push_back(str);
                str = "";
                
            }
            
        }
        
    }
    
    if(str != "")
        answer++;
    
    
    return answer;
}