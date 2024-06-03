// 피보나치 / baekjoon_9009.cpp
// https://www.acmicpc.net/problem/9009

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int t;
long long fibonacci[51];

void solve() {

    int n, temp;
    stack<int> s;

    cin >> n;

    while (true) {

        if (n == 0)
            break;

        for (int i = 0; i <= 50; i++) {
            if (fibonacci[i] <= n) 
                temp = fibonacci[i];
        }

        n -= temp;
        s.push(temp);
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    
    cout << '\n';

}

void input() {
    cin >> t;

    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for (int i = 2; i <= 50; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    while (t--) {
        solve();
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

}
