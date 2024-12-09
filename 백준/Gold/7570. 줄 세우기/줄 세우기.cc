#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N + 1);
    vector<int> pos(N + 1);

    // 번호별 위치 기록
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        pos[v[i]] = i; // 번호가 줄에서 서 있는 위치를 저장
    }

    int max_length = 1;
    int length = 1;

    // 번호 순서대로 pos 배열을 탐색하면서 연속 증가 구간 찾기
    for (int i = 2; i <= N; i++) {
        if (pos[i] > pos[i - 1]) { // 이전 번호의 위치보다 크면 연속 증가
            length++;
            max_length = max(max_length, length);
        } else length = 1;
    }

    cout << N - max_length << "\n"; 
    return 0;
}
