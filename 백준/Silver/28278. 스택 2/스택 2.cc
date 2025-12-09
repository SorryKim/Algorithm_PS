#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> st;
    st.reserve(N); 

    while (N--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x;
            cin >> x;
            st.push_back(x);
        }
        else if (cmd == 2) {
            if (st.empty()) cout << -1 << "\n";
            else {
                cout << st.back() << "\n";
                st.pop_back();
            }
        }
        else if (cmd == 3) {
            cout << st.size() << "\n";
        }
        else if (cmd == 4) {
            cout << (st.empty() ? 1 : 0) << "\n";
        }
        else if (cmd == 5) {
            if (st.empty()) cout << -1 << "\n";
            else cout << st.back() << "\n";
        }
    }

    return 0;
}
