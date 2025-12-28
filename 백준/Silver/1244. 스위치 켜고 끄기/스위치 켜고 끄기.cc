#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> sw(N + 1);
    for (int i = 1; i <= N; i++) cin >> sw[i];
    

    int S;
    cin >> S;

    while (S--) {
        int gender, k;
        cin >> gender >> k;
        
        if (gender == 1) {
            for (int i = k; i <= N; i += k) {
                sw[i] = 1 - sw[i];
            }
        }
        else {
            int left = k;
            int right = k;

            while (left - 1 >= 1 && right + 1 <= N &&
                   sw[left - 1] == sw[right + 1]) {
                left--;
                right++;
            }

            for (int i = left; i <= right; i++) {
                sw[i] = 1 - sw[i];
            }
        }
    }

   
    for (int i = 1; i <= N; i++) {
        cout << sw[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }
    if (N % 20 != 0) cout << "\n";

    return 0;
}
