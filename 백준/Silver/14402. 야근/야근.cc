#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<string, long long> cnt;
    long long overtime = 0;

    for(int i = 0; i < q; i++){
        string name;
        char p;
        cin >> name >> p;

        if(p == '+'){
            cnt[name]++;
        }else{ // '-'
            if(cnt[name] == 0){
                // 들어간 기록 없이 나감 → 야근
                overtime++;
            }else{
                cnt[name]--;
            }
        }
    }

    // 끝났는데 아직 남아있는 사람들 → 전부 야근
    for(auto &it : cnt){
        overtime += it.second;
    }

    cout << overtime << "\n";
    return 0;
}