#include <iostream>
using namespace std;

short arr[1000001];

int searchIdx(int start, int end) {

    int maxV = arr[start];
    int maxIdx = 0;

    if (start == end)
        return -1;

    for (int i = start; i <= end; i++) {
        if (maxV < arr[i]) {
            maxIdx = i;
            maxV = arr[i];
        }
    }

    if (maxV == arr[start])
        return -1;

    return maxIdx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        long long N;
        long long ans = 0;
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> arr[i];
        
        int maxV = -1;

        for (int i = N - 1; i >= 0; i--) {

            int now = arr[i];
            if (maxV > arr[i]) {
                ans += maxV - arr[i];
            }

            if (maxV < arr[i])
                maxV = arr[i];
        }

        cout << "#" << test << " " << ans << "\n";
    }
}