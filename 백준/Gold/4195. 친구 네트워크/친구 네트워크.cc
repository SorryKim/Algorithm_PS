#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent; // 부모 확인
unordered_map<string, int> cnt; // 친구 네트워크 수 확인

string Find(string s){
    if(parent[s] == s)
        return s;
    else return parent[s] = Find(parent[s]);
}

void Union(string s1, string s2){

    string p1 = Find(s1);
    string p2 = Find(s2);

    if(cnt[p1] < cnt[p2]){
        parent[p2] = p1;
        cnt[p1] += cnt[p2];
    }
    else{
        parent[p1] = p2;
        cnt[p2] += cnt[p1];
    }
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    
    while(tc--){

        // Input
        int F;
        cin >> F;
        parent.clear();
        cnt.clear();

        for(int i = 0; i < F; i++){
            string s1,s2;
            cin >> s1 >> s2;

            // 둘 다 처음인 경우
            if(parent.find(s1) == parent.end() && parent.find(s2) == parent.end()){
                parent[s1] = s1;
                parent[s2] = s1;
                cnt[s1] = 2;
            }
            // 둘 다 존재할 경우
            else if(parent.find(s1) != parent.end() && parent.find(s2) != parent.end()){
                string parent1 = Find(s1);
                string parent2 = Find(s2);
                
                // 둘이 다른 네트워크일 경우
                if(parent1 != parent2)
                    Union(s1, s2);
            }
            // s1만 존재하는 경우
            else if(parent.find(s1) != parent.end()){
                cnt[s2] = 1;
                parent[s2] = s2;
                Union(s1,s2);
                
            }
            // s2만 존재하는 경우
            else if(parent.find(s2) != parent.end()){
                cnt[s1] = 1;
                parent[s1] = s1;
                Union(s1,s2);
            }

            cout << cnt[Find(s1)] << '\n';
            
        }

    }

    return 0;
}
