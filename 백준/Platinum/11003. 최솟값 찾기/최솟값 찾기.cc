#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        // 현재 수보다 큰 값들은 데크에서 제거
        while (!dq.empty() && v[dq.back()] > v[i]) {
            dq.pop_back();
        }

        // 현재 인덱스를 데크에 추가
        dq.push_back(i);

        // 데크의 앞쪽 원소가 윈도우를 벗어났다면 제거
        if (dq.front() < i - L + 1) {
            dq.pop_front();
        }

        // 현재 윈도우의 최솟값 출력
        cout << v[dq.front()] << " ";
    }

    return 0;
}
