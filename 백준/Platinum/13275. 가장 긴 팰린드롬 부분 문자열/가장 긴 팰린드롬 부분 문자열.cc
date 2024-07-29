#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string Pre(const string& s) {
    string temp = "#";

    for (auto a : s) {
        temp += a;
        temp += "#";
    }

    return temp;
}

int Manacher(const string& s) {

 
    int right = 0; // 현재까지 발견된 오른쪽 팰린드롬의 가장 오른쪽 위치
    int center = 0; // 현재까지 발견된 가장 오른쪽 팰린드롬의 중앙
    int n = s.size();
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {

        // 현재까지 발견된 가장 오른쪽 팰린드롬의 왼쪽 위치
        int left = 2 * center - i;

        // 초기 값 설정
        if (i <= right)
            v[i] = min(v[left], right - i);

        // i 기준 팰린드롬 값 계산
        while (i + v[i] + 1 < n && i - v[i] - 1 >= 0 && s[i + v[i] + 1] == s[i - v[i] - 1])
            v[i]++;

        if (i + v[i] > right) {
            center = i;
            right = i + v[i];
        }

    }

    // 최댓값 탐색
    sort(v.begin(), v.end());
    return v[n - 1];
}

int main(void) {
    

    string s;
    cin >> s;

    s = Pre(s);
    
    int answer = Manacher(s);
    cout << answer;
    return 0;
}
