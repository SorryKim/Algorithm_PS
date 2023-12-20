#include <iostream>
using namespace std;

int l, r, k;

void Input() {
    cin >> l >> r >> k;
}

void Solve() {

    int ans = 0;

    switch (k)
    {

    // 2인 경우 3이상의 모든 수 가능
    case 2:
        for (int i = 3; i <= r; i++) {
            if (i >= l && i <= r)
                ans++;  
        }
        break;

    // 3인 경우 6이상의 3의 배수 가능
    case 3:
        for (int i = 6; i <= r; i += 3) {
            if (i >= l && i <= r)
                ans++;
        }
        break;
    // 4인 경우, 10이상의 짝수 단, 12제외
    case 4:
        for (int i = 10; i <= r; i += 2) {
            if (i == 12)
                continue;
            if (i >= l && i <= r)
                ans++;
        }
        break;

    // 5인 경우, 15이상의 5의 배수
    case 5:
        for (int i = 15; i <= r; i += 5) {
            if (i >= l && i <= r)
                ans++;
        }
        break;
    }
   

    cout << ans << "\n";
}

int main() {

    Input();
    Solve();

    return 0;
}
