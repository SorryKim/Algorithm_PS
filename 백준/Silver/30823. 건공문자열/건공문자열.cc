#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    string s;
    cin >> s;


    string front = s.substr(k - 1);
    string back = s.substr(0, k - 1);

    int num = n - k + 1;

    if (num % 2 == 1) reverse(back.begin(), back.end());
    
    
    cout << front << back << "\n";

    return 0;
}