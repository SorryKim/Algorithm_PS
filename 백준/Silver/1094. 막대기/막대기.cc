#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    cin >> X;

    int cnt = 0;

    while (X > 0)
    {
        if ((X & 1) == 1)
            cnt++;
        X >>= 1;
    }

    cout << cnt << '\n';
    return 0;
}
