// 소수의 연속합 / baekjoon_1644.cpp
// https://www.acmicpc.net/problem/1644

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 4000000
int N;
bool arr[MAX + 1];
vector<int> v;

void Input() {

    cin >> N;

}


void Solve() {

    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i <= MAX; i++)
        arr[i] = true;

    // 에라토스테네스의 체
    for (int i = 2; i * i <= MAX; i++) {
        if (arr[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                arr[j] = false;
            }
        }
    }

    for (int i = 0; i <= MAX; i++) {
        if (arr[i])
            v.push_back(i);
    }

    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;
    
    while (true) {

        if (sum >= N)
            sum -= v[left++];

        else if (right >= v.size())
            break;

        else if(sum < N) 
            sum += v[right++];
    

        if (sum == N)
            cnt++;     
    }


    cout << cnt << "\n";
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    
}
