#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool answer = true;

    for(int i = 0; i < s.size() / 2; i++){

        if(s[i] != s[s.size() - i - 1]){
            answer = false;
            break;
        }
    }

    int ans = answer ? 1 : 0;
    cout << ans;

    return 0;
}
