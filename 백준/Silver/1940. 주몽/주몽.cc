#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cnt = 0;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = n - 1;


    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == m) {
            cnt++;
            left++;
            right--;
        }
        else if (sum < m) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << cnt << '\n';

    return 0;
}
