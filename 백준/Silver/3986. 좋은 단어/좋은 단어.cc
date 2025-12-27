#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int ans = 0;

    while (N--) {
        string s;
        cin >> s;

        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) st.pop();       
            else st.push(c);  
        }

        if (st.empty()) ans++;
    }

    cout << ans << "\n";
    return 0;
}
