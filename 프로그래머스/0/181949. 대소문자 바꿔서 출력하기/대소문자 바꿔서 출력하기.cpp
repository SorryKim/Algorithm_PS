#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
    string str;
    int val = 'A' - 'a';
    
    cin >> str;
    
    
    string ans = "";
    
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(islower(ch)){
            ans += ch + val;
        }else{
            ans += ch - val;
        }
    }
    
    cout << ans;
    return 0;
}