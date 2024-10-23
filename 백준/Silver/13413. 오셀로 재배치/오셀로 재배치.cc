#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while(TC--){
        
        int N;
        int cnt_W1 = 0;
        int cnt_W2 = 0;
        cin >> N;

        string s, target;
        cin >> s >> target;

        for(int i = 0; i < N; i++){
            if(s[i] == 'W')
                cnt_W1++;
            if(target[i] == 'W')
                cnt_W2++;
        }

        int cnt = abs(cnt_W1 - cnt_W2);
        int answer = 0;
        
        // 색의 숫자와 자리숫자 세기
        for(int i = 0; i < N; i++){
            if(s[i] != target[i])
                answer++;
        }
        
        answer -= cnt;
        answer = ceil((double)answer / 2.0);
        answer += cnt;

        cout << answer << '\n';

    }
    

    return 0;
}
