#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<string, int> mp;

    for(int i = 0; i < N; i++){
        string name;
        cin >> name;
        mp[name]++;
    }

    int cnt = 0;

    vector<string> ans;

    for(auto a : mp){
        if(a.second > cnt){
            cnt = a.second;
            ans.clear();
            ans.push_back(a.first);
        }else if(a.second == cnt){
            ans.push_back(a.first);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << "\n";

    return 0;
}