#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int temp = 10;

    while (N >= temp) {
        if (N % temp >= 5 * (temp / 10)) N += (temp - (N % temp));
        else N -= N % temp;
        temp *= 10;
    }

    cout << N << "\n";
    return 0;
}
