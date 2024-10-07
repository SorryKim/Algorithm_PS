#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int answer = 0;
    char target[5] = {'a', 'e', 'i', 'o', 'u'};

    for(auto now : s){
        for(auto a : target){
            if(a == now)
                answer++;
        }
    }
    
    cout << answer << endl;
    return 0;
}