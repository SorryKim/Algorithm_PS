// 좋다 / baekjjon_1253.cpp
// https://www.acmicpc.net/problem/1253

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

void Input() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

}

void Solve() {

    sort(v.begin(), v.end());
    
    int result = 0;

  
    for (int i = 0; i < N; i++) {

        int now = v[i];
        int left = 0;
        int right = N - 1;

        while (left < right) {

            // 자기자신이 포함되는 경우
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }


            int sum = v[left] + v[right];

            if (sum == now) {
                result++;
                break;
            }

            else if (now > sum) {
                left++;
            }
            else
                right--;
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
