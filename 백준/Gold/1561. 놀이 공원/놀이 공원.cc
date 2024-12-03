#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> attractions(M + 1);

    for (int i = 1; i <= M; i++)
        cin >> attractions[i];
    

    if (N <= M) {
        cout << N << '\n';
        return 0;
    }

    long long left = 0, right = 1e16;
    long long time = 0; // N번째 아이가 타는 시간

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = M; // 모든 놀이기구는 0초에 시작

        for (int i = 1; i <= M; i++)
            sum += mid / attractions[i]; // 각 놀이기구에서 mid 시간까지 탄 아이 수

        if (sum >= N) {
            time = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // time - 1까지 탄 아이 수 계산
    long long sum = M;
    for (int i = 1; i <= M; i++)
        sum += (time - 1) / attractions[i];

    // N번째 아이가 탈 놀이기구 찾기
    for (int i = 1; i <= M; i++) {
        if (time % attractions[i] == 0) {
            sum++;
            if (sum == N) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}
