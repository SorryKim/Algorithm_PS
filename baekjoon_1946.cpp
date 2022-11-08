// 신입 사원 / baekjoon_1946.cpp
// https://www.acmicpc.net/problem/1946

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> arr[100001];

// 서류 성적 오름차순 정렬
bool cmp(pair<int, int> p1, pair<int, int> p2) {

    if (p1.first < p2.first)
        return true;

    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    while (T--) {
    
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            arr[i].first = a;
            arr[i].second = b;
        }
        
        sort(arr, arr + N, cmp);
        
        int result = 1;
        int temp = 0; // 면접성적 최고자

        
        for (int i = 1; i < N; i++) {

            if (arr[i].second < arr[temp].second) {
                result++;
                temp = i;
            }
        }

        cout << result << "\n";
    }

}
