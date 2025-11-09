#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    long long sum = 0;       
    long long xorSum = 0;    
    unordered_map<long long, int> cnt;

    cnt[0] = 1;
    sum = 0;
    xorSum = 0;

    while (M--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            long long x;
            cin >> x;
            cnt[x]++;
            sum += x;
            xorSum ^= x;
        }
        else if (cmd == 2) {
            long long x;
            cin >> x;
            cnt[x]--;
            sum -= x;
            xorSum ^= x;
            if (cnt[x] == 0) cnt.erase(x);
        }
        else if (cmd == 3) {
            cout << sum << '\n';
        }
        else if (cmd == 4) {
            cout << xorSum << '\n';
        }
    }

    return 0;
}
