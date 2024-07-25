#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v;

bool cmp(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 + s2 > s2 + s1;
}

int main() {
    int N;
    string answer = "";
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto a : v) {
        answer += to_string(a); // 숫자를 문자열로 변환하여 결합
    }

    
    bool flag = false;
    for (auto a : answer) {
        if (a != '0') {
            flag = true;
            break;
        }
    }

    if (!flag)
        answer = "0";

    cout << answer;

    return 0;
}
