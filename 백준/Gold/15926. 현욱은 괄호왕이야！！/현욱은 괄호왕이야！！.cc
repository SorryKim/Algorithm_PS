#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    stack<int> st;
    int answer = 0;

    // 초기값으로 유효하지 않은 위치 설정
    st.push(-1);

    for (int i = 0; i < n; i++) {

        char now = s[i];
        if(now == '(') st.push(i);
        else{
            if(!st.empty())
                st.pop();
            
            if(st.empty()) st.push(i);
            else answer = max(answer, i - st.top());
        }
    }

    cout << answer << '\n';
    return 0;

}
