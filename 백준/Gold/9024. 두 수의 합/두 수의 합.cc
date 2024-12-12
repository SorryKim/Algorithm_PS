#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        int left = 0, right = n - 1;
        int val = 1e9;
        int cnt = 0;

        // 투 포인터 탐색
        while (left < right) {
            int sum = v[left] + v[right];
            int diff = abs(sum - k);

            if (diff < val) {
                val = diff;
                cnt = 1; // 새로운 최소 차이가 나오면 카운트를 초기화
            } else if (diff == val) cnt++; // 동일한 최소 차이가 나오면 카운트를 증가
            

            if (sum < k) left++;
            else right--;
        }

        cout << cnt << "\n";
    }

    return 0;
}