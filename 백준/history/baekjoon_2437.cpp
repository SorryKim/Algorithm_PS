// 저울 / baekjoon_2437.cpp
// https://www.acmicpc.net/problem/2437

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[1000];

void Input() {

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

}



void Solve() {

    sort(arr, arr + N);
    int temp = 1;

    for (int i = 0; i < N; i++) {

        if (arr[i] > temp) {
            break;
        }
        temp += arr[i];
    }
    
    cout << temp << "\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();
}
