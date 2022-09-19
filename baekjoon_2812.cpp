// 크게 만들기 / baekjoon_2812.cpp
// https://www.acmicpc.net/problem/2812

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int N, K;
string s;

void Input() {

    cin >> N >> K;
    cin >> s;

}

void Solve() {

    stack<char> st;
    string result = "";
    
    for (int i = 0; i < N; i++) {

        while (!st.empty() && K > 0 && st.top() < s[i]) {
            K--;
            st.pop();
        }
        st.push(s[i]);
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.length() - K; i++)
        cout << result[i];

    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();
}
