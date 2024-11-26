#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;

    int a = 1; 
    int b = 0; 

    for (int i = 0; i < K; i++) {
        int newA = b;         
        int newB = a + b;    
        a = newA;
        b = newB;
    }

    cout << a << " " << b << '\n';
    return 0;
}