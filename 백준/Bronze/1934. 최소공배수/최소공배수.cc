#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int GCD(int a, int b){
    
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int LCM(int a, int b){
    return ((a*b) / GCD(a,b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){

        int a,b;
        cin >> a >> b;

        if(a >= b)
            cout << LCM(a,b) << '\n';
        else
            cout << LCM(b,a) << '\n';
    }

    return 0;
}