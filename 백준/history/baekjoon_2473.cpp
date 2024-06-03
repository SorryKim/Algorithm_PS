// 세 용액 / baekjoon_2473.cpp
// https://www.acmicpc.net/problem/2473

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long arr[5000];

void Input() {

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

}

void Solve() {
    
    sort(arr, arr + N);

    int fixV = 0;
    int start = 1;
    int end = N - 1;
    long long temp;
    long long minV = 33333333333;
    int result[3] = { arr[0], arr[1], arr[2] };

    
    for (int i = 0; i < N - 1; i++) {

        fixV = i;
        start = fixV + 1;
        end = N - 1;

        while (start < end) {

            temp = arr[fixV] + arr[start] + arr[end];

            if (abs(minV) > abs(temp)) {
                result[0] = arr[fixV];
                result[1] = arr[start];
                result[2] = arr[end];
                minV = abs(temp);
            }

            if (temp == 0)
                break;

            if (temp > 0) 
                end--;
            else 
                start++;
        }
    }
    

    cout << result[0] << " " << result[1] << " " << result[2] << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();

}
