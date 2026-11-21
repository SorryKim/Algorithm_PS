
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    int lamp[50][50];
    int answer = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        for(int j = 0; j < M; j++){
            lamp[i][j] = s[j] - '0';
        }
    }

    cin >> K;

    for(int i = 0; i < N; i++){

        int cnt = 0;

        for(int j = 0; j < M; j++){
            if(lamp[i][j] == 0) cnt++;
        }

        // 해당 행은 전부 키기 불가능
        if(cnt > K) continue;
        if((K - cnt) % 2 != 0) continue;
        
        
        int ans = 1;
        for(int k = i + 1; k < N; k++){
            bool b = true;
            for(int j = 0; j < M; j++){
                if(lamp[i][j] != lamp[k][j]){
                    b = false;
                    break;
                }
            }
            if(b) ans++;
        }

        answer = max(answer, ans);
    }

    cout << answer << '\n';
    return 0;
}
