#include <iostream>
using namespace std;

int main() {
    int T, S;
    cin >> T >> S;
    
    bool flag = (T >= 12 && T <= 16);

    // 밥알 갯수 결정
    if (flag && S == 0) cout << 320 << '\n';
    else cout << 280 << '\n';
    
    return 0;
}
