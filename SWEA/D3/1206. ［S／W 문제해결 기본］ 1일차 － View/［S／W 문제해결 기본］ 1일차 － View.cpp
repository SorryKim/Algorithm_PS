#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int Func(int n) {
    int sum = 0;
    int now = v[n];
    int a = v[n - 2];
    int b = v[n - 1];
    int c = v[n + 1];
    int d = v[n + 2];

    if (now > a && now > b && now > c && now > d) {
        sum = now - max(a, max(b, max(c, d)));
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 10;

    for (int test = 1; test <= T; test++) {
        int N;
        cin >> N;
        int ans = 0;

        v.clear();

        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        for (int i = 2; i < N - 2; i++) {
            ans += Func(i);
        }

        cout << "#" << test << " " << ans << "\n";
    }

    return 0;
}
