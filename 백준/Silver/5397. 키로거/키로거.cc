#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    while(TC--){
        string L;
        cin >> L;

        stack<char> result, temp;

        for(int i = 0; i < L.size(); i++){
            char now = L[i];
            if(now == '<'){
                if(result.empty()) continue;
                char ch = result.top();
                result.pop();
                temp.push(ch);
            }else if(now == '>'){
                if(temp.empty()) continue;
                char ch = temp.top();
                temp.pop();
                result.push(ch);
            }else if(now == '-'){
                if(result.empty()) continue;
                result.pop();
            }else result.push(now);
            
        }

        while(!temp.empty()){
            char ch = temp.top();
            result.push(ch);
            temp.pop();
        }

        string ans = "";
        while(!result.empty()){
            ans += result.top();
            result.pop();
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

}