#include <iostream>

using namespace std;

string solve(long long n, long long m){
    if(n == 1) return "YES";
    if((m - n) % 2 == 0) return "NO";
    else return "YES";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--)
    {
        long long n, m;
        cin >> n >> m;
        cout << solve(min(n, m), max(n, m)) << "\n";
    }

    return 0;
}