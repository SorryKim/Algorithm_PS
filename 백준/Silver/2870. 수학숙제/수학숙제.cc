#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 앞의 0 제거 함수
string trim(const string &s) {
    int i = 0;
    while (i < (int)s.size() && s[i] == '0') i++;
    string res = s.substr(i);
    return res.empty() ? "0" : res;
}

// 비교 함수
bool cmp(const string &a, const string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> numbers;

    while (N--) {
        string line;
        cin >> line;

        string now = "";
        for (char c : line) {
            if (isdigit(c)) {
                now += c;
            } else {
                if (!now.empty()) {
                    numbers.push_back(trim(now));
                    now.clear();
                }
            }
        }
        if (!now.empty()) {
            numbers.push_back(trim(now));
        }
    }

    sort(numbers.begin(), numbers.end(), cmp);

    for (auto &num : numbers) cout << num << '\n';
    return 0;
}
