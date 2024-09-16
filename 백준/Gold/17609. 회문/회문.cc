#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>

using namespace std;

int Check(string s, int start, int end, bool flag){

    while(start <= end){
        
        if(s[start] != s[end]){
            
            // 문자 1개 제거에서 확인
            if(flag){
                int v1 = Check(s, start + 1, end, false);
                int v2 = Check(s, start, end - 1, false);

                return min(v1, v2);
            }
            else
                return 2;
        }

        start++;
        end--;
    }


    // 유사회문인 경우
    if(!flag)
        return 1;
    
    // 회문
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--){

        string s;
        cin >> s;

        int start = 0;
        int end = s.size() - 1;

        int ans = Check(s, 0, s.size() - 1, true);
        cout << ans << '\n';
    }


    return 0;
}
