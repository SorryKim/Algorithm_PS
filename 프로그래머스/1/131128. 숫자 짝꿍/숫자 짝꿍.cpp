#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int a[10] = {0, };
    int b[10] = {0, };
    
    for(auto temp : X){
        int now = temp - '0';
        a[now]++;
    }
    
    for(auto temp : Y){
        int now = temp - '0';
        b[now]++;
    }
    
    for(int i = 9; i >= 0; i--){
        int cnt = min(a[i],b[i]);
        
        while(cnt--){
            answer += to_string(i);
        }
    }
    
    if(answer == "")
        answer = "-1";
    
    if(answer[0] == '0')
        answer = "0";
    
    for(auto temp : a){
        cout << temp <<" ";
    }
    cout << endl;
    for(auto temp : b){
        cout << temp <<" ";
    }
    
    return answer;
}