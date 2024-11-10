#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string answer = (N % 2 == 0) ? "SK" : "CY";
    cout <<  answer << '\n';

    return 0;
}
