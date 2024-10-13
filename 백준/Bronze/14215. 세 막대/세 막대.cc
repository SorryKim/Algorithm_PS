#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int sticks[3] = {a, b, c};
    sort(sticks, sticks + 3);

    while (sticks[0] + sticks[1] <= sticks[2])
        sticks[2]--;
    
    int answer = sticks[0] + sticks[1] + sticks[2];

    cout << answer;

    return 0;
}