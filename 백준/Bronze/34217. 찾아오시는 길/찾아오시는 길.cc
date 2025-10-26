#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;
    
    int val1 = A + C;
    int val2 = B + D;

    if(val1 < val2) cout << "Hanyang Univ.";
    else if(val1 > val2) cout << "Yongdap";
    else cout << "Either";
}