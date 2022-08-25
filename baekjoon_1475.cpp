// 방 번호 / baekjoon_1475.cpp
// https://www.acmicpc.net/problem/1475

#include<iostream>
#include<string>
using namespace std;

string s;

void input() {
   
    cin >> s;

}

void solve() {

    int arr[10];

    for (int i = 0; i < 10; i++)
        arr[i] = 0;

    for (int i = 0; i < s.length(); i++) {
        int n = s[i] - '0';
        arr[n]++;
    }

    arr[6] = ((arr[6] + arr[9]) % 2) + ((arr[6] + arr[9]) / 2);
    arr[9] = 0;

    int result = 0;

    for (auto a : arr) {
        result = max(result, a);
    }

    cout << result << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();

}
