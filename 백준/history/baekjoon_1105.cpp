// 팔 / baekjoon_1105.cpp
// https://www.acmicpc.net/problem/1105

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string L, R;

void Input() {
    
    cin >> L >> R;
}


void Solve() {
    
    int result = 0;
    bool b = true;

    // 자릿수가 다르면 무조건 8이없는 수가 존재할 수 있다.
    if (L.length() == R.length()) {

        for (int i = 0; i < L.length(); i++) {

            // 앞에서 달라지면 8이 안나와도 된다.
            if (L[i] != R[i])
                b = false;

            if (L[i] == R[i] && L[i] == '8' && b)
                result++;
        }
    }
    

    cout << result << "\n";


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    
}
