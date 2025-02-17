#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<string> v;

    for(int i = 0; i < s.size(); i++){
        string temp = "";

        for(int j = i; j < s.size(); j++){
            temp += s[j];
        }

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for(auto ans : v) cout << ans << '\n';
    

    
    return 0;
}
