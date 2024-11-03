#include <iostream>
#include <vector>

using namespace std;

int dp[2501][2501];
bool isPalindrome[2501][2501];

bool Check(string s){

    for(int i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    // 펠린드롬 범위 기록
    for (int i = 0; i < s.size(); i++) isPalindrome[i][i] = true;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1])
            isPalindrome[i][i + 1] = true;
    }

    for(int len = 3; len <= s.size(); len++){
        for(int start = 0; start + len <= s.size(); start++){
            int end = start + len - 1;
            if(s[start] == s[end] && isPalindrome[start + 1][end - 1])
                isPalindrome[start][end] = true;  
        }
    }

    
    for(int end = 0; end < s.size(); end++){

        if(isPalindrome[0][end])
            dp[0][end] = 1;
        else{

            // 초기값은 모두 펠린드롬이 아닌 경우
            dp[0][end] = end + 1;
            for(int i = 0; i < end; i++){
                // i ~ end 펠린드롬 여부 확인 
                if(isPalindrome[i + 1][end]){
                    dp[0][end] = min(dp[0][end], dp[0][i] + 1);
                }
            }
        }
    }
    
    cout << dp[0][s.size() - 1];

    return 0;
}
