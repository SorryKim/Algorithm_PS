#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int swaps;
string num;
int ans;


void DFS(int start, int cnt) {
    string result = "";
    if (cnt == swaps) {
        int val = stoi(num);
        ans = max(ans, val);
        return;
    }

    for (int i = start; i < num.length(); i++) {
        for (int j = i + 1; j < num.length(); j++) {
            char temp = num[i];
            num[i] = num[j];
            num[j] = temp;

            DFS(i, cnt + 1);
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }

    return;
}

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
 
        cin >> num >> swaps;
        ans = 0;
        if (swaps > num.length())
            swaps = num.length();

        DFS(0, 0);

        cout << "#" << testCase << " " << ans << "\n";
    }

    return 0;
}
