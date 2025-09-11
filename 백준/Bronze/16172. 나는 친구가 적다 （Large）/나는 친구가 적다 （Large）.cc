#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, K;
    cin >> S >> K;

    string temp = "";
    for (int i = 0; i < S.size(); i++)
    {
        if (isalpha(S[i]))
            temp += S[i];
    }

    cout << (temp.find(K) != string::npos ? 1 : 0);

    return 0;
}
