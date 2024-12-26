#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    bool flag = true;
    cin >> N;
    cin.ignore();

    string temp[7] = {
        "Never gonna give you up", 
        "Never gonna let you down",
        "Never gonna run around and desert you", 
        "Never gonna make you cry",
        "Never gonna say goodbye", 
        "Never gonna tell a lie and hurt you", 
        "Never gonna stop"
    };

    while (N--) {
        string now;
        getline(cin, now);

        bool found = false;
        for (const auto& s : temp) {
            if (now == s) {
                found = true;
                break;
            }
        }
        if (!found) {
            flag = false; 
        }
    }

    string answer = flag ? "No" : "Yes"; 
    cout << answer << '\n';

    return 0;
}
