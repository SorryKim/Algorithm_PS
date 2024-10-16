#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    int idx = 1;
    while(tc--){
        int a, b;
        cin >> a >> b;
        cout << "Case " << idx << ": " << a + b << endl;
        idx++;
    }
    return 0;
}