#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {

        vector<int> v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];

        // LIS
        vector<int> temp;
        for (int i = 0; i < N; i++) {
            if (temp.size() == 0 || v[i] > temp.back())
                temp.push_back(v[i]);
            else {
                // lower_bound를 사용하여 v[i] 이상의 첫 번째 위치를 찾음
                int idx = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
                temp[idx] = v[i];
            }
        }

        cout << temp.size() << '\n';
    }

    return 0;
}
