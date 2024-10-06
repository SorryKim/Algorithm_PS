#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a,b;
    cin >> a >> b;

    if(a > b)
        swap(a,b);
    
    if(b - a >= 2){
        cout << b - a - 1 << '\n';
        for(long i = a + 1; i < b; i++)
            cout << i << ' ';
    }
    else
        cout << 0 << '\n';

    return 0;
}
