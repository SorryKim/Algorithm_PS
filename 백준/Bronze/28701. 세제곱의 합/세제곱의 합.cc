/*
    C++: Hello, World!
*/
#include <iostream>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long ans1 = 0, ans2 = 0, ans3 = 0;

    for(int i = 1; i <= N; i++){
        ans1 += i;
        ans3 += i*i*i;
    }

    cout << ans1 << "\n";
    cout << ans1 * ans1 << "\n";
    cout << ans3 << "\n";

    return 0;
}
