#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    string ans = n%2 == 0 ? "even" : "odd";
    
    cout << n << " is " << ans;
    return 0;
}