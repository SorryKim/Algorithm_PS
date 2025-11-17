#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int temp = N;

        for (int i = 2; i * i <= temp; i++) {
            if (temp % i == 0) {
                int cnt = 0;
                while (temp % i == 0) {
                    temp /= i;
                    cnt++;
                }
                cout << i << " " << cnt << "\n";
            }
        }

        if (temp > 1) {
            cout << temp << " 1\n";  // 남은 소수
        }
    }
    return 0;
}
