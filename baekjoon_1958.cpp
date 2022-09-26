// LCS 3 / baekjoon_1958.cpp
// https://www.acmicpc.net/problem/1958

#include <iostream>
#include <string>
using namespace std;

string s1, s2, s3;
int dp[101][101][101] = {0, };

void Input() {
    cin >> s1 >> s2 >> s3;
}

void Solve() {
   
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            for (int k = 1; k <= s3.length(); k++) {
                if (s2[j - 1] == s3[k - 1] && s3[k - 1] == s1[i - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }

    cout << dp[s1.length()][s2.length()][s3.length()];
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    Solve();

}
