// 인간-컴퓨터 상호작용 / baekjoon_16139.cpp
// https://www.acmicpc.net/problem/16139

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;
int q, arr[222222][26];

void Input() {
  
    cin >> str;
    cin >> q;
}


void Solve() {
  

    for (int i = 0; i < str.length(); i++) {

        if (i != 0) {
            for (int j = 0; j < 26; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }    
        arr[i][str[i] - 'a']++;
    }

    for (int i = 0; i < q; i++) {

        char ch;
        int left, right;

        cin >> ch;
        cin >> left >> right;

        int now = ch - 'a';
        int num1, num2;

        if (left > 0) 
            num1 = arr[left - 1][now];
        else
            num1 = 0;

        num2 = arr[right][now];
        cout << num2 - num1 << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

}
