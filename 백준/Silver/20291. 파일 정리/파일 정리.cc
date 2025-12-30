#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<string, int> mp;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        bool flag = false;
        string tmp = "";
        for(char ch : s){
            if(ch == '.'){
                flag = true;
                continue;
            }
            if(!flag) continue;

            tmp += ch;
        }

        mp[tmp]++;
    }

    for(auto now : mp){
        cout << now.first << " " << now.second << "\n";
    }

    return 0;
}