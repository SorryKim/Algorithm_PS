#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<bool> used(26, false);
    for(char c : s) used[c - 'a'] = true;
    
    // 1. 아직 안 쓴 문자가 있는 경우 작은 문자 한개 뒤에 붙이기
    if(s.size() < 26){
        for(int i = 0; i < 26; i++){
            if(!used[i]){
                cout << s << char('a' + i) << "\n";
                return 0;
            }
        }
    }

    // 2. 길이 26인 경우 다음 순서로 가기
    int n = s.size();

    // 뒤에서부터 처음으로 s[i] < s[i+1] 찾기
    int i = n - 2;
    while(i >= 0 && s[i] >= s[i+1]) i--;

    if(i < 0){
        // 완전 내림차순 → 마지막 순열
        cout << -1 << "\n";
        return 0;
    }

    // 뒤쪽에서 s[i]보다 큰 것 중 가장 작은 것 찾기
    int j = n - 1;
    while(s[j] <= s[i]) j--;

    swap(s[i], s[j]);
    cout << s.substr(0, i + 1) << "\n";
    return 0;
}