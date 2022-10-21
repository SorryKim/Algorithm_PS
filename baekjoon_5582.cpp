// 공통 부분 문자열 / baekjoon_5582.cpp
// https://www.acmicpc.net/problem/5582

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s1, s2;
int dp[4001][4001];

void Input() {

    cin >> s1 >> s2;
 
}

void Solve() {

    int result = 0;

    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++)
            dp[i][j] = 0;
    }

    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(dp[i][j], result);
            }
        }
    }

    cout << result << "\n";
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    Input();
    Solve();
}
